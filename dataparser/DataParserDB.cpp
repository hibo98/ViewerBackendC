#include "DataParserDB.h"

DataParserDB::DataParserDB(sql::ResultSet* result)
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
    bool autoupdate = this->result->getBoolean("autoupdate");
    return this->result->wasNull() ? false : autoupdate;
}

QString DataParserDB::getCommunity()
{
    return QString(this->result->getString("community").c_str());
}

QString DataParserDB::getEMail()
{
    return QString(this->result->getString("email").c_str());
}

QString DataParserDB::getFirmwareBase()
{
    return QString(this->result->getString("firmwareBase").c_str());
}

QString DataParserDB::getFirmwareVersion()
{
    return QString(this->result->getString("firmwareVersion").c_str());
}

long long DataParserDB::getFirstseen()
{
    return this->result->getInt64("firstseen") * 1000LL;
}

long long DataParserDB::getLastseen()
{
    return this->result->getInt64("lastseen") * 1000LL;
}

double DataParserDB::getLongitude()
{
    double lon = static_cast<double>(this->result->getDouble("longitude"));
    return this->result->wasNull() ? 0 : lon;
}

double DataParserDB::getLatitude()
{
    double lat = static_cast<double>(this->result->getDouble("latitude"));
    return this->result->wasNull() ? 0 : lat;
}

QString DataParserDB::getModel()
{
    return QString(this->result->getString("model").c_str());
}

QString DataParserDB::getName()
{
    return QString(this->result->getString("name").c_str());
}

NodeType DataParserDB::getRole()
{
    QString s = QString(this->result->getString("role").c_str());
    if (s == "node") {
        return STANDARD;
    } else {
        return STANDARD;
        //@TODO: Include other node types
    }
}

bool DataParserDB::isGateway()
{
    return this->result->getBoolean("gateway");
}

bool DataParserDB::isOnline()
{
    return false;
}
