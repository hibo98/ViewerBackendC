#include "DataParserDB.h"

#include <QVariant>

DataParserDB::DataParserDB(QSqlQuery result)
{
    this->result = result;
}

DataParserDB::DataParserDB(const DataParserDB& orig) : DataParserDB(orig.result)
{
}

DataParserDB::~DataParserDB()
{
}

QJsonObject DataParserDB::getData()
{
    if (!this->r.empty()) {
        return this->r;
    }
    this->r.insert("autoupdate", QJsonValue(this->getAutoUpdate()));
    this->r.insert("community", QJsonValue(this->getCommunity()));
    this->r.insert("email", QJsonValue(this->getEMail()));
    this->r.insert("firmwareBase", QJsonValue(this->getFirmwareBase()));
    this->r.insert("firmwareVersion", QJsonValue(this->getFirmwareVersion()));
    this->r.insert("firstseen", QJsonValue(QString::number(this->getFirstseen())));
    this->r.insert("lastseen", QJsonValue(QString::number(this->getLastseen())));
    this->r.insert("lat", QJsonValue(this->getLatitude()));
    this->r.insert("lon", QJsonValue(this->getLongitude()));
    this->r.insert("model", QJsonValue(this->getModel()));
    this->r.insert("name", QJsonValue(this->getName()));
    this->r.insert("role", QJsonValue(this->getRole()));
    this->r.insert("online", QJsonValue(this->isOnline()));
    this->r.insert("gateway", QJsonValue(this->isGateway()));
    return this->r;
}

bool DataParserDB::hasLinkSet()
{
    return false;
}

void DataParserDB::getLinkSet(QSet<Link*>*)
{
}

bool DataParserDB::getAutoUpdate()
{
    QVariant autoupdate = this->result.value("autoupdate");
    return autoupdate.isNull() ? false : autoupdate.toBool();
}

QString DataParserDB::getCommunity()
{
    return this->result.value("community").toString();
}

QString DataParserDB::getEMail()
{
    return this->result.value("email").toString();
}

QString DataParserDB::getFirmwareBase()
{
    return this->result.value("firmwareBase").toString();
}

QString DataParserDB::getFirmwareVersion()
{
    return this->result.value("firmwareVersion").toString();
}

long long DataParserDB::getFirstseen()
{
    return this->result.value("firstseen").toLongLong() * 1000LL;
}

long long DataParserDB::getLastseen()
{
    return this->result.value("lastseen").toLongLong() * 1000LL;
}

double DataParserDB::getLongitude()
{
    QVariant lon = this->result.value("longitude");
    return lon.isNull() ? 0 : lon.toDouble();
}

double DataParserDB::getLatitude()
{
    QVariant lat = this->result.value("latitude");
    return lat.isNull() ? 0 : lat.toDouble();
}

QString DataParserDB::getModel()
{
    return this->result.value("model").toString();
}

QString DataParserDB::getName()
{
    return this->result.value("name").toString();
}

NodeType DataParserDB::getRole()
{
    QString s = this->result.value("role").toString();
    if (s == "node") {
        return STANDARD;
    } else {
        return STANDARD;
        //@TODO: Include other node types
    }
}

bool DataParserDB::isGateway()
{
    return this->result.value("gateway").toBool();
}

bool DataParserDB::isOnline()
{
    return false;
}
