
/* 
 * File:   Node.cpp
 * Author: NMerkelt
 * 
 * Created on 17. Oktober 2018, 13:11
 */

#include "Node.h"

Node::Node(int id) {
    this->id = id;
}

Node::Node(const Node& orig) : Node(orig.id) {
}

Node::~Node() {
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

int Node::getId() {
    return this->id;
}

QSet<Link*> Node::getLinks() {
    return this->links;
}

signed char Node::getClients() {
    return this->clients;
}

bool Node::isValid() {
    return this->valid;
}

bool Node::isDisplayed() {
    return this->display && this->isValid();
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
        this->clients = (signed char) json.value("clients").toInt();
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
        this->firstseen = json.value("firstseen").toString().toLong();
    }
    if (json.contains("lat") && json.contains("lon")) {
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
        this->type = (NodeType) json.value("role").toInt();
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
