#include "MySQL.h"

#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlQuery>

MySQL::MySQL() {
    QString d = QString("Available drivers: ");
    QStringList drivers = QSqlDatabase::drivers();
    for (int i = 0; i < drivers.size(); i++) {
        d += drivers.at(i) + " ";
    }
    std::cout << d.toStdString() << std::endl;

    if (this->loadCfg()) {
        this->openConnection();
    } else {
        this->createCfg();
        if (this->loadCfg()) {
            this->openConnection();
        }
    }
}

MySQL::~MySQL() {
    this->connection.close();
}

bool MySQL::loadCfg() {
    QFile config("config.json");
    if (!config.exists()) {
        return false;
    }
    if (!config.open(QIODevice::ReadOnly)) {
        std::cerr << "Couldn't open file:" << "config.json" << std::endl;
        return false;
    }
    QByteArray saveData = config.readAll();

    QJsonDocument configDoc(QJsonDocument::fromJson(saveData));
    QJsonObject cfg = configDoc.object();
    if (!(cfg.contains("host") && cfg.contains("username") && cfg.contains("password") && cfg.contains("database"))) {
        std::cerr << "Failure in config file format, createing config file..." << std::endl;
        return false;
    }
    this->host = cfg.value("host").toString();
    this->username = cfg.value("username").toString();
    this->password = cfg.value("password").toString();
    this->database = cfg.value("database").toString();
    return true;
}

void MySQL::createCfg() {
    QJsonObject jsonObject;
    jsonObject.insert("host", QJsonValue(QString("tcp://127.0.0.1:3306")));
    jsonObject.insert("username", QJsonValue(QString("username")));
    jsonObject.insert("password", QJsonValue(QString("password")));
    jsonObject.insert("database", QJsonValue(QString("database")));
    QJsonDocument graphDoc(jsonObject);
    QFile config("config.json");
    if (!config.open(QIODevice::WriteOnly)) {
        std::cerr << "Couldn't open file:" << "config.json" << std::endl;
        return;
    }
    config.write(graphDoc.toJson(QJsonDocument::Indented));
}

bool MySQL::openConnection() {
    if (!this->connection.isValid()) {
        this->connection = QSqlDatabase::addDatabase("QMYSQL");
        connection.setHostName(this->host);
        connection.setDatabaseName(this->database);
        connection.setUserName(this->username);
        connection.setPassword(this->password);
    }
    return this->connection.open();
}

bool MySQL::hasConnection() {
    return this->connection.isOpen();
}

void MySQL::closeConnection() {
    this->connection.close();
}

bool MySQL::execute(QString query) {
    return this->connection.exec().exec(query);
}

QSqlQuery MySQL::executeQuery(QString query) {
    return this->connection.exec(query);
}

QSqlQuery MySQL::prepareStatement(QString query) {
    QSqlQuery q = this->connection.exec();
    q.prepare(query);
    return q;
}

