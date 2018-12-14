#include "MySQL.h"

#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlQuery>
#include <QSqlError>

MySQL::MySQL() {
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
        std::cerr << "Failure in config file format, (re)createing config file..." << std::endl;
        return false;
    }
    this->host = cfg.value("host").toString();
    this->port = cfg.contains("port") ? static_cast<short>(cfg.value("port").toInt()) : 3306;
    this->username = cfg.value("username").toString();
    this->password = cfg.value("password").toString();
    this->database = cfg.value("database").toString();
    return true;
}

void MySQL::createCfg() {
    QJsonObject jsonObject;
    jsonObject.insert("host", QJsonValue(QString("127.0.0.1")));
    jsonObject.insert("port", QJsonValue(3306));
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
        connection.setPort(this->port);
        connection.setDatabaseName(this->database);
        connection.setUserName(this->username);
        connection.setPassword(this->password);
    }
    return this->connection.open();
}

bool MySQL::reconnect() {
    this->connection.close();
    return this->connection.open();
}

bool MySQL::hasConnection() {
    return this->connection.isOpen();
}

void MySQL::closeConnection() {
    this->connection.close();
}

bool MySQL::execute(QString query) {
    if (!this->hasConnection()) {
        this->reconnect();
    }
    return this->connection.exec().exec(query);
}

QSqlQuery MySQL::executeQuery(QString query) {
    if (!this->hasConnection()) {
        this->reconnect();
    }
    return this->connection.exec(query);
}

QSqlQuery MySQL::prepareStatement(QString query) {
    QSqlQuery q = this->connection.exec();
    q.prepare(query);
    return q;
}

bool MySQL::execPS(QSqlQuery ps) {
    if (!this->hasConnection()) {
        this->reconnect();
    }
    bool exec = ps.exec();
    if (!exec) {
        std::cerr << ps.lastError().text().toStdString() << std::endl;
    }
    return exec;
}
