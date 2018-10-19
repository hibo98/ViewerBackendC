
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
    
    if (json.contains("clients")) {
        this->clients = (signed char) json.value("clients").toInt();
    }
    if (json.contains("firstseen")) {
        this->firstseen = json.value("firstseen").toString().toLong();
    }
    if (json.contains("lastseen")) {
        this->firstseen = json.value("firstseen").toString().toLong();
    }
    if (json.contains("lat") && json.contains("lon")) {
        this->location = new Location(json.value("lat").toDouble(), json.value("lon").toDouble());
    }
    if (json.contains("name")) {
        this->name = json.value("name").toString();
    }
    if (json.contains("online")) {
        this->online = json.value("online").toBool();
    }
    if (json.contains("gateway")) {
        this->gateway = json.value("gateway").toBool();
    }
    if (dp->hasLinkSet()) {
        this->links = *dp->getLinkSet();
    }
}

int Node::convertIpToId(QString ip) {
    QStringList split = ip.split('.');
    if (split.size() == 4) {
        return split.at(2).toInt() * 255 + split.at(3).toInt() - 1;
    }
    return -1;
}

QString Node::convertIdToMac(int id) {
    return QString("ff:dd:00:00:%1:%2")
            .arg(id / 255 % 256, 0, 16)
            .arg((id % 255) + 1, 0, 16);
}

QString Node::convertIdToIp(int id) {
    return Node::convertIdToIp(id, false);
}

QString Node::convertIdToIp(int id, bool subnet201) {
    return QString("10.%1.%2.%3")
            .arg(subnet201 ? 201 : 200)
            .arg(id / 255 % 256)
            .arg((id % 255) + 1);
}
