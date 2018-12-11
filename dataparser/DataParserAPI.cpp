#include "DataParserAPI.h"

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
    this->r.insert("autoupdate", QJsonValue(this->getAutoUpdate()));
    this->r.insert("clients", QJsonValue(this->getClients()));
    this->r.insert("firmwareVersion", QJsonValue(this->getFirmwareVersion()));
    this->r.insert("firstseen", QJsonValue(QString::number(this->getFirstseen())));
    this->r.insert("gatewayIp", QJsonValue(this->getGatewayIp()));
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

void DataParserAPI::getLinkSet(QSet<Link*>*) {
}

bool DataParserAPI::getAutoUpdate() {
    return this->json.value("status").toObject().value("autoupdate").toBool(false);
}

int DataParserAPI::getClients() {
    return this->json.value("status").toObject().value("clients").toInt(0);
}

QString DataParserAPI::getFirmwareVersion() {
    return this->json.value("firmware").toString();
}

long long DataParserAPI::getFirstseen() {
    return this->json.value("status").toObject().value("firstseen").toString().toLongLong() * 1000;
}

QString DataParserAPI::getGatewayIp() {
    return this->json.value("status").toObject().value("selected_gateway").toString();
}

long long DataParserAPI::getLastseen() {
    return this->json.value("status").toObject().value("lastseen").toString().toLongLong() * 1000;
}

double DataParserAPI::getLatitude() {
    return this->json.value("position").toObject().value("lat").toDouble();
}

double DataParserAPI::getLongitude() {
    return this->json.value("position").toObject().value("lon").toDouble();
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
