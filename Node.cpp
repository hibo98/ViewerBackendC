#include "Node.h"
#include "Util.h"
#include "DataGen.h"
#include "StatsSQL.h"

#include <iostream>
#include <QJsonArray>
#include <QJsonValue>
#include <QStringList>
#include <QSqlError>

Node::Node(int id) {
    this->id = id;
}

Node::Node(const Node& orig) : Node(orig.id) {
}

Node::~Node() {
    delete this->location;
}

QString Node::getHostname() {
    if (this->name.isNull() || this->name.isEmpty()) {
        return QString::number(this->id);
    } else {
        return QString::number(this->id).append('-').append(this->name);
    }
}

QString Node::getFakeMac() {
    return QString("ff:dd:00:00:%1:%2")
            .arg(this->id / 255 % 256, 0, 16)
            .arg((this->id % 255) + 1, 0, 16);
}

QString Node::getIpAddress(bool subnet201) {
    return QString("10.%1.%2.%3")
            .arg(subnet201 ? 201 : 200)
            .arg(this->id / 255 % 256)
            .arg((this->id % 255) + 1);
}

QString Node::getNodeType() {
    switch (this->type) {
        case STANDARD:
            return QString("standard");
    }
}

int Node::getId() {
    return this->id;
}

QSet<Link*> Node::getLinks() {
    return this->links;
}

short Node::getClients() {
    return this->clients;
}

bool Node::isValid() {
    return this->valid;
}

bool Node::isDisplayed() {
    return this->isValid() && (this->lastseen > Util::getCurrentTimestamp() - Util::DAYS_30);
}

bool Node::isOnline() {
    return this->online;
}

bool Node::hasValidLocation() {
    return this->location->isValid();
}

void Node::fill(DataParser* dp) {
    QJsonObject json = dp->getData();
    
    if (json.contains("autoupdate")) {
        this->autoupdate = json.value("autoupdate").toBool();
    }
    if (json.contains("clients")) {
        this->clients = json.value("clients").toString().toShort();
    }
    if (json.contains("community")) {
        this->community = json.value("community").toString();
    }
    if (json.contains("email")) {
        this->email = json.value("email").toString();
    }
    if (json.contains("firmwareBase")) {
        this->firmwareBase = json.value("firmwareBase").toString();
    }
    if (json.contains("firmwareVersion")) {
        this->firmwareVersion = json.value("firmwareVersion").toString();
    }
    if (json.contains("firstseen")) {
        this->firstseen = json.value("firstseen").toString().toLong();
    }
    if (json.contains("gatewayIp")) {
        this->gatewayIp = json.value("gatewayIp").toString();
    }
    if (json.contains("lastseen")) {
        this->lastseen = json.value("lastseen").toString().toLong();
    }
    if (json.contains("lat") && json.contains("lon")) {
        if (this->location != nullptr) {
            delete this->location;
        }
        this->location = new Location(json.value("lat").toDouble(), json.value("lon").toDouble());
    }
    if (json.contains("load")) {
        this->avgLoad = json.value("load").toDouble();
    }
    if (json.contains("memory")) {
        this->memoryUsage = json.value("memory").toDouble();
    }
    if (json.contains("model")) {
        this->model = json.value("model").toString();
    }
    if (json.contains("name")) {
        this->name = json.value("name").toString();
    }
    if (json.contains("role")) {
        this->type = NodeType(json.value("role").toInt());
    }
    if (json.contains("uptime")) {
        this->uptime = json.value("uptime").toDouble();
    }
    if (json.contains("online")) {
        this->online = json.value("online").toBool();
    }
    if (json.contains("gateway")) {
        this->gateway = json.value("gateway").toBool();
    }
    if (dp->hasLinkSet()) {
        dp->getLinkSet(&this->links);
    }
    this->valid = true;
}

QJsonObject Node::getJsonObjectHop() {
    QJsonObject node;
    QJsonObject nodeinfo;
    QJsonObject network;
    QJsonArray addresses;
    addresses.append(QJsonValue(this->getIpAddress()));
    network.insert("addresses", QJsonValue(addresses));
    nodeinfo.insert("network", QJsonValue(network));
    nodeinfo.insert("hostname", QJsonValue(this->getHostname()));
    QJsonObject system;
    system.insert("site_code", QJsonValue(this->community));
    system.insert("role", this->getNodeType());
    nodeinfo.insert("system", QJsonValue(system));
    QJsonObject hardware;
    if (!this->model.isEmpty()) {
        hardware.insert("model", QJsonValue(this->model));
    }
    nodeinfo.insert("hardware", QJsonValue(hardware));
    nodeinfo.insert("node_id", QJsonValue(this->id));
    QJsonObject software;
    QJsonObject autoupdater;
    autoupdater.insert("enabled", QJsonValue(this->autoupdate));
    autoupdater.insert("branch", "stable");
    software.insert("autoupdater", autoupdater);
    if (!this->firmwareVersion.isEmpty()) {
        QJsonObject firmware;
        firmware.insert("release", QJsonValue(this->firmwareVersion));
        firmware.insert("base", QJsonValue(this->firmwareBase));
        software.insert("firmware", QJsonValue(firmware));
    }
    nodeinfo.insert("software", software);
    QJsonObject owner;
    if (!this->email.isEmpty()) {
        owner.insert("contact", QJsonValue(this->email));
    }
    nodeinfo.insert("owner", QJsonValue(owner));
    if (this->id > 1000 && this->hasValidLocation()) {
        nodeinfo.insert("location", QJsonValue(this->location->toJson()));
    }
    node.insert("nodeinfo", QJsonValue(nodeinfo));
    QJsonObject statistics;
    statistics.insert("clients", QJsonValue(this->clients));
    if (this->isOnline()) {
        statistics.insert("uptime", QJsonValue(this->uptime));
        statistics.insert("memory_usage", QJsonValue(this->memoryUsage));
        statistics.insert("loadavg", QJsonValue(this->avgLoad));
    }
    if (!this->gateway && !this->gatewayIp.isEmpty()) {
        statistics.insert("gateway", QJsonValue(this->gatewayIp));
    }
    node.insert("statistics", QJsonValue(statistics));
    QJsonObject flags;
    flags.insert("gateway", QJsonValue(this->gateway));
    flags.insert("uplink", QJsonValue(this->gateway)); //@TODO: correct with direct connection to internet
    flags.insert("online", QJsonValue(this->online));
    node.insert("flags", QJsonValue(flags));
    node.insert("firstseen", QJsonValue(Util::getTimeString(this->firstseen)));
    node.insert("lastseen", QJsonValue(Util::getTimeString(this->lastseen)));
    return node;
}

QJsonObject Node::getJsonObjectMesh() {
    QJsonObject node;
    node.insert("firstseen", QJsonValue(Util::getTimeString(this->firstseen)));
    node.insert("lastseen", QJsonValue(Util::getTimeString(this->lastseen)));
    node.insert("is_gateway", QJsonValue(this->gateway));
    node.insert("is_online", QJsonValue(this->online));
    node.insert("clients", QJsonValue(this->clients));
    node.insert("clients_wifi24", QJsonValue(this->clients));
    node.insert("clients_wifi5", QJsonValue(0));
    node.insert("clients_other", QJsonValue(0));
    if (this->online) {
        node.insert("loadavg", QJsonValue(this->avgLoad));
        node.insert("memory_usage", QJsonValue(this->memoryUsage));
        long long date = Util::getCurrentTimestamp() - (static_cast<long long>(this->uptime) * 1000);
        node.insert("uptime", QJsonValue(Util::getTimeString(date)));
        node.insert("nproc", QJsonValue(1)); //TODO: Correct processor count
    }
    if (!this->gateway && !this->gatewayIp.isEmpty()) {
        node.insert("gateway", QJsonValue(QString::number(convertIpToId(this->gatewayIp))));
        node.insert("gateway_nexthop", QJsonValue(QString::number(convertIpToId(this->gatewayIp)))); //TODO: Correct value
    }
    node.insert("node_id", QJsonValue(QString::number(this->id)));
    QJsonArray addresses;
    addresses.append(QJsonValue(this->getIpAddress()));
    node.insert("addresses", QJsonValue(addresses));
    node.insert("site_code", QJsonValue(this->community));
    node.insert("hostname", QJsonValue(this->getHostname()));
    if (this->id > 1000 && this->hasValidLocation()) {
        node.insert("location", QJsonValue(this->location->toJson()));
    }
    if (!this->firmwareVersion.isEmpty()) {
        QJsonObject firmware;
        firmware.insert("release", QJsonValue(this->firmwareVersion));
        firmware.insert("base", QJsonValue(this->firmwareBase));
        node.insert("firmware", QJsonValue(firmware));
    }
    if (!this->model.isEmpty()) {
        node.insert("model", QJsonValue(this->model));
    }
    node.insert("contact", QJsonValue(this->email));
    QJsonObject autoupdater;
    autoupdater.insert("enabled", QJsonValue(this->autoupdate));
    autoupdater.insert("branch", QJsonValue("stable"));
    node.insert("autoupdater", QJsonValue(autoupdater));
    node.insert("vpn", QJsonValue(this->gateway)); //TODO: Correct value
    node.insert("mac", QJsonValue(this->getFakeMac()));
    return node;
}

void Node::updateDatabase()
{
    if (!this->hasValidLocation()) {
        QSqlQuery ps = DataGen::getDatabase()->prepareStatement("INSERT INTO nodes SET id = ? ON DUPLICATE KEY UPDATE id = id");
        ps.addBindValue(this->id);
        if (!DataGen::getDatabase()->execPS(ps)) {
            std::cerr << ps.lastError().text().toStdString() << std::endl;
        }
    } else {
        QSqlQuery ps = DataGen::getDatabase()->prepareStatement("INSERT INTO nodes SET id = ?, latitude = ?, longitude = ? ON DUPLICATE KEY UPDATE latitude = ?, longitude = ?");
        ps.addBindValue(this->id);
        ps.addBindValue(this->location->getLatitude());
        ps.addBindValue(this->location->getLongitude());
        ps.addBindValue(this->location->getLatitude());
        ps.addBindValue(this->location->getLongitude());
        if (!DataGen::getDatabase()->execPS(ps)) {
            std::cerr << ps.lastError().text().toStdString() << std::endl;
        }
    }
    QSqlQuery ps = DataGen::getDatabase()->prepareStatement("UPDATE nodes SET community = ?, role = ?, model = ?, firmwareVersion = ?, firmwareBase = ?, firstseen = ?, lastseen = ?, online = ?, autoupdate = ?, gateway = ?, name = ?, email = ? WHERE id = ?");
    ps.addBindValue(this->community);
    ps.addBindValue(this->getNodeType());
    ps.addBindValue(this->model);
    ps.addBindValue(this->firmwareVersion);
    ps.addBindValue(this->firmwareBase);
    ps.addBindValue(static_cast<int>(this->firstseen / 1000));
    ps.addBindValue(static_cast<int>(this->lastseen / 1000));
    ps.addBindValue(this->online);
    ps.addBindValue(this->autoupdate);
    ps.addBindValue(this->gateway);
    ps.addBindValue(this->name);
    ps.addBindValue(this->email);
    ps.addBindValue(this->id);
    if (!DataGen::getDatabase()->execPS(ps)) {
        std::cerr << ps.lastError().text().toStdString() << std::endl;
    }
    //Statistics
    if (this->isOnline() && (this->id >= 1000 && this->id < 51000)) {
        StatsSQL::addClientStat(this, this->clients);
        StatsSQL::addLoadStat(this, static_cast<float>(this->avgLoad));
        StatsSQL::addMemoryStat(this, this->memoryUsage);
    }
}

void Node::setOnline(bool online) {
    this->online = online;
}

int Node::convertIpToId(QString ip) {
    QStringList split = ip.split('.');
    if (split.size() == 4) {
        return split.at(2).toInt() * 255 + split.at(3).toInt() - 1;
    }
    return -1;
}
