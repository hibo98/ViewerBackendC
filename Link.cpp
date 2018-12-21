#include "Link.h"

#include <cmath>

Link::Link(LinkType type, Node* source, Node* target, short sourceTq, short targetTq) {
    this->type = type;
    this->sourceTq = sourceTq;
    this->targetTq = targetTq;
    this->source = source;
    this->target = target;
}

Link::Link(const Link& orig) : Link(orig.type, orig.source, orig.target, orig.sourceTq, orig.targetTq) {
}

Link::~Link() = default;

Node* Link::getSource() {
    return this->source;
}

Node* Link::getTarget() {
    return this->target;
}

short Link::getSourceTq() {
    return this->sourceTq;
}

void Link::setSourceTq(short tq) {
    this->sourceTq = tq;
}

short Link::getTargetTq() {
    return this->targetTq;
}

void Link::setTargetTq(short tq) {
    this->targetTq = tq;
}

LinkType Link::getLinkType() {
    return this->type;
}

QString Link::getTypeHopglass() {
    switch (this->type) {
        case TUNNEL:
            return "tunnel";
        case OTHER:
            return "other";
        case WIRELESS:
            return "wireless";
    }
    return "other";
}

QString Link::getTypeMeshViewer() {
    switch (this->type) {
        case TUNNEL:
            return "vpn";
        case OTHER:
            return "other";
        case WIRELESS:
            return "wifi";
    }
    return "other";
}

LinkType Link::getLinkTypeByInterface(QString s) {
    s = s.toLower();
    if (s == "wlan0") {
        return WIRELESS;
    } else if (s == "br-tbb" || s == "br-meshwire" || s == "br-mesh_lan" || s == "br-mesh_wan") {
        return OTHER;
    } else if (s == "tbb-fastd" || s == "tbb_fastd" || s == "tbb_fastd2") {
        return TUNNEL;
    } else {
        return OTHER;
    }
}

LinkType Link::getLinkTypeByType(QString s) {
    s = s.toLower();
    if (s == "lan") {
        return OTHER;
    } else if (s == "wifi") {
        return WIRELESS;
    } else if (s == "backbone") {
        return TUNNEL;
    } else {
        return OTHER;
    }
}

double Link::convertToHopGlass(short tq) {
    return tq < 1 ? 100000 : (std::round(100 / tq * 1000) / 1000);
}

double Link::convertToMeshViewer(short tq) {
    return tq == -1 ? 0 : tq / 100;
}
