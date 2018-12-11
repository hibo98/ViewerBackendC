#include "MySQL.h"

#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/statement.h>

MySQL::MySQL() {
    if (this->loadCfg()) {
        if (!this->openConnection()) {
            std::cerr << "No connection to database!" << std::endl;
        }
    } else {
        this->createCfg();
        if (this->loadCfg()) {
            if (!this->openConnection()) {
                std::cerr << "No connection to database!" << std::endl;
            }
        }
    }
}

MySQL::~MySQL() {
    this->closeConnection();
    delete this->connection;
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
    this->host = sql::SQLString(cfg.value("host").toString().toStdString());
    this->username = sql::SQLString(cfg.value("username").toString().toStdString());
    this->password = sql::SQLString(cfg.value("password").toString().toStdString());
    this->database = sql::SQLString(cfg.value("database").toString().toStdString());
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
    sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
    if (this->connection == nullptr) {
        this->connection = driver->connect(this->host, this->username, this->password);
        this->connection->setSchema(this->database);
        return this->hasConnection();
    } else {
        if (this->connection->isClosed()) {
            delete this->connection;
            this->connection = nullptr;
            return this->openConnection();
        } else {
            return this->connection->reconnect();
        }
    }
}

bool MySQL::hasConnection() {
    return this->connection != nullptr && this->connection->isValid();
}

void MySQL::closeConnection() {
    this->connection->close();
}

bool MySQL::execute(sql::SQLString sql) {
    return this->connection->createStatement()->execute(sql);
}

sql::ResultSet* MySQL::executeQuery(sql::SQLString sql) {
    return this->connection->createStatement()->executeQuery(sql);
}

sql::PreparedStatement* MySQL::prepareStatement(sql::SQLString sql) {
    return this->connection->prepareStatement(sql);
}

