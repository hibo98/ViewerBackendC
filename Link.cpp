
/* 
 * File:   Link.cpp
 * Author: NMerkelt
 * 
 * Created on 13. Oktober 2018, 15:06
 */

#include "Link.h"

Link::Link(LinkType type, signed char sourceTq, signed char targetTq, Node* source, Node* target) {
    this->type = type;
    this->sourceTq = sourceTq;
    this->targetTq = targetTq;
    this->source = source;
    this->target = target;
}

Link::Link(const Link& orig) : Link(orig.type, orig.sourceTq, orig.targetTq, orig.source, orig.target) {
}

Link::~Link() {
}

QString Link::getTypeHopglass() {
    switch (this->type) {
        case TUNNEL:
            return "tunnel";
        case OTHER:
            return "other";
        case WIRELESS:
        default:
            return "wireless";
    }
}

QString Link::getTypeMeshViewer() {
    switch (this->type) {
        case TUNNEL:
            return "vpn";
        case OTHER:
            return "other";
        case WIRELESS:
        default:
            return "wifi";
    }
}

