#include "DataParserSysinfo.h"
#include "../DataGen.h"
#include "../Util.h"

#include <QJsonArray>
#include <QStringList>
#include <QUrl>

DataParserSysinfo::DataParserSysinfo(QJsonObject json, int version) {
    this->data = json;
    this->version = version;
    if (this->data.contains("statistic")) {
        stats = this->data.value("statistic").toObject();
    } else {
        stats = this->data.value("statistics").toObject();
    }
}

DataParserSysinfo::DataParserSysinfo(const DataParserSysinfo& orig) : DataParserSysinfo(orig.data, orig.version) {
}

DataParserSysinfo::~DataParserSysinfo() {
}

QJsonObject DataParserSysinfo::getData() {
    if (!this->r.empty()) {
        return this->r;
    }
    this->r.insert("autoupdate", QJsonValue(this->getAutoUpdate()));
    this->r.insert("clients", QJsonValue(this->getClients()));
    this->r.insert("community", QJsonValue(this->getCommunity()));
    this->r.insert("email", QJsonValue(this->getEMail()));
    this->r.insert("firmwareBase", QJsonValue(this->getFirmwareBase()));
    this->r.insert("firmwareVersion", QJsonValue(this->getFirmwareVersion()));
    this->r.insert("gatewayIp", QJsonValue(this->getGatewayIp()));
    this->r.insert("lastseen", QJsonValue(QString::number(this->getLastseen())));
    this->r.insert("lat", QJsonValue(this->getLatitude()));
    this->r.insert("lon", QJsonValue(this->getLongitude()));
    this->r.insert("load", QJsonValue(this->getLoadAvg()));
    this->r.insert("memory", QJsonValue(this->getMemoryUsage()));
    this->r.insert("model", QJsonValue(this->getModel()));
    this->r.insert("name", QJsonValue(this->getName()));
    this->r.insert("role", QJsonValue(this->getRole()));
    this->r.insert("uptime", QJsonValue(this->getUptime()));
    this->r.insert("online", QJsonValue(this->isOnline()));
    return this->r;
}

bool DataParserSysinfo::hasLinkSet() {
    return true;
}

void DataParserSysinfo::getLinkSet(QSet<Link*>* links) {
    Node* node = DataGen::getDataHolder()->getNode(this->getNodeId());
    QJsonObject bmxd = this->data.value("bmxd").toObject();
    if (this->version <= 10) {
        QJsonObject rt = bmxd.contains("routing_tables") ? bmxd.value("routing_tables").toObject() : bmxd.value("RoutingTables").toObject();
        QJsonArray lnks = rt.value("route").toObject().value("link").toArray();
        for (int i = 0; i < lnks.size(); i++) {
            QJsonObject l = lnks[i].toObject();
            int targetId = Node::convertIpToId(l.value("target").toString());
            if (targetId != -1) {
                LinkType linkType = Link::getLinkTypeByInterface(l.value("interface").toString());
                Node* target = DataGen::getDataHolder()->getNode(targetId);
                links->insert(new Link(linkType, target, node));
            }
        }
    }
    if (bmxd.contains("links")) {
        QJsonArray lnks = bmxd.value("links").toArray();
        for (int i = 0; i < lnks.size(); i++) {
            QJsonObject l = lnks[i].toObject();
            Node* target = DataGen::getDataHolder()->getNode(l.value("node").toInt());
            signed char tq = static_cast<signed char>(l.value("tq").toString().toShort());
            if (this->version == 10) {
                QList<Link*> linkmap = links->values();
                for (int i = 0; i < linkmap.size(); i++) {
                    Link* lnk = linkmap[i];
                    if (lnk->getTarget() == target) {
                        lnk->setSourceTq(tq);
                        break;
                    }
                }
            } else if (version >= 11 && version < 14) {
                LinkType linkType = Link::getLinkTypeByInterface(l.value("interface").toString());
                links->insert(new Link(linkType, target, node, tq));
            } else if (version >= 14) {
                LinkType linkType = Link::getLinkTypeByType(l.value("type").toString());
                links->insert(new Link(linkType, target, node, tq));
            }
        }
    }
}

int DataParserSysinfo::getNodeId() {
    return this->data.value("common").toObject().value("node").toInt();
}

bool DataParserSysinfo::getAutoUpdate() {
    if (version >= 14) {
        return this->data.value("system").toObject().value("autoupdate").toInt(0) == 1;
    } else {
        return false;
    }
}

int DataParserSysinfo::getClients() {
    return this->stats.value("accepted_user_count").toInt(0);
}

QString DataParserSysinfo::getCommunity() {
    QString com = this->data.value("common").toObject().value("city").toString();
    if (com.isEmpty()) {
        return "Dresden";
    }
    if (com == "Meissen") {
        return "Meißen";
    }
    return com;
}

QString DataParserSysinfo::getEMail() {
    return QUrl::fromPercentEncoding(this->data.value("contact").toObject().value("email").toString().toUtf8());
}

QString DataParserSysinfo::getFirmwareBase() {
    QJsonObject firmware = this->data.value("firmware").toObject();
    QString DISTRIB_ID = firmware.value("DISTRIB_ID").toString();
    QString DISTRIB_RELEASE = firmware.value("DISTRIB_RELEASE").toString();
    QString DISTRIB_REVISION = firmware.value("DISTRIB_REVISION").toString();
    return DISTRIB_ID + " " + DISTRIB_RELEASE + " " + DISTRIB_REVISION;
}

QString DataParserSysinfo::getFirmwareVersion() {
    return this->data.value("firmware").toObject().value("version").toString();
}

QString DataParserSysinfo::getGatewayIp() {
    return this->data.value("bmxd").toObject().value("gateways").toObject().value("selected").toString();
}

long long DataParserSysinfo::getLastseen() {
    return Util::getCurrentTimestamp();
}

double DataParserSysinfo::getLoadAvg() {
    return this->stats.value("cpu_load").toString().split(" ")[0].toDouble();
}

double DataParserSysinfo::getLongitude() {
    return this->data.value("gps").toObject().value("longitude").toDouble();
}

double DataParserSysinfo::getLatitude() {
    return this->data.value("gps").toObject().value("latitude").toDouble();
}

double DataParserSysinfo::getMemoryUsage() {
    if (this->stats.contains("meminfo_MemTotal") && this->stats.contains("meminfo_MemFree")) {
        double memTotal = this->stats.value("meminfo_MemTotal").toString().split(" ")[0].toDouble();
        double memFree = this->stats.value("meminfo_MemFree").toString().split(" ")[0].toDouble();
        return (memTotal - memFree) / memTotal;
    } else {
        return -1;
    }
}

QString DataParserSysinfo::getModel() {
    return this->data.value("system").toObject().value(version >= 14 ? "model2" : "model").toString();
}

QString DataParserSysinfo::getName() {
    return QUrl::fromPercentEncoding(this->data.value("contact").toObject().value("name").toString().toUtf8());
}

NodeType DataParserSysinfo::getRole() {
    if (version >= 13) {
        QString s = this->data.value("system").toObject().value("node_type").toString();
        if (s == "node") {
            return STANDARD;
        } else {
            return STANDARD;
            //@TODO: Include other node types
        }
    }
    return STANDARD;
}

double DataParserSysinfo::getUptime() {
    QString jsonUptime = this->data.value("system").toObject().value("uptime").toString();
    QStringList uptime = jsonUptime.replace("  ", " ").split(" ");
    if (version < 10 && jsonUptime.contains(":")) {
        if (uptime[3].replace(",", "").contains(":")) {
            return parseMinutes(uptime[3].replace(",", "")) * 60;
        } else {
            short days = uptime[3].replace(",", "").toShort();
            int min;
            QString minutes = uptime[5].replace(",", "");
            QString time = uptime[6].replace(",", "");
            if (minutes.isEmpty()) {
                min = parseMinutes(time);
            } else {
                min = parseMinutes(minutes);
            }
            return min * 60 + days * 86400;
        }
        //Ab v10
    } else {
        return uptime[0].toDouble();
    }
}

bool DataParserSysinfo::isOnline() {
    return true;
}

int DataParserSysinfo::parseMinutes(QString time) {
    if (time.contains(":")) {
        return time.split(":")[0].toInt() * 60 + time.split(":")[1].toInt();
    } else {
        return time.toInt();
    }
}
