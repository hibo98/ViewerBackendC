
/* 
 * File:   DataParserAPI.cpp
 * Author: NMerkelt
 * 
 * Created on 18. Oktober 2018, 22:58
 */

#include "DataParserAPI.h"

#include <cmath>
#include <QJsonValue>

DataParserAPI::DataParserAPI(QJsonObject json) {
    this->json = json;
}

DataParserAPI::DataParserAPI(const DataParserAPI& orig) : DataParserAPI(orig.json) {
}

DataParserAPI::~DataParserAPI() {
}

QJsonObject DataParserAPI::getData() {
    if (!this->r.empty()) {
        return this->r;
    }
    this->r.insert("clients", QJsonValue(this->getClients()));
    this->r.insert("firstseen", QJsonValue(QString::number(this->getFirstseen())));
    this->r.insert("lastseen", QJsonValue(QString::number(this->getLastseen())));
    this->r.insert("lat", QJsonValue(this->getLatitude()));
    this->r.insert("lon", QJsonValue(this->getLongitude()));
    this->r.insert("name", QJsonValue(this->getName()));
    this->r.insert("online", QJsonValue(this->isOnline()));
    this->r.insert("gateway", QJsonValue(this->isGateway()));
    return this->r;
}

bool DataParserAPI::hasLinkSet() {
    return false;
}

QSet<Link*>* DataParserAPI::getLinkSet() {
    return nullptr;
}

int DataParserAPI::getClients() {
    return this->json.value("status").toObject().value("clients").toInt(0);
}

long DataParserAPI::getFirstseen() {
    return this->json.value("status").toObject().value("firstseen").toString().toLong() * 1000;
}

long DataParserAPI::getLastseen() {
    return this->json.value("status").toObject().value("lastseen").toString().toLong() * 1000;
}

double DataParserAPI::getLatitude() {
    double d = this->json.value("position").toObject().value("lat").toDouble();
    return d == 0 ? std::nan("") : d;
}

double DataParserAPI::getLongitude() {
    double d = this->json.value("position").toObject().value("lon").toDouble();
    return d == 0 ? std::nan("") : d;
}

QString DataParserAPI::getName() {
    return this->json.value("name").toString();
}

bool DataParserAPI::isOnline() {
    return this->json.value("status").toObject().value("online").toBool();
}

bool DataParserAPI::isGateway() {
    return this->json.value("status").toObject().value("gateway").toBool();
}
