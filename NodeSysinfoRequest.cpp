
/* 
 * File:   NodeSysinfoRequest.cpp
 * Author: NMerkelt
 * 
 * Created on 22. Oktober 2018, 18:15
 */

#include "NodeSysinfoRequest.h"
#include "Node.h"
#include "dataparser/DataParserSysinfo.h"

#include <iostream>
#include <QJsonObject>

NodeSysinfoRequest::NodeSysinfoRequest(Node* n) : QObject(nullptr) {
    this->n = n;
    this->request = new JsonRequest(new QUrl("http://" + this->n->getIpAddress() + "/sysinfo-json.cgi"));
    connect(this->request, &JsonRequest::result, this, &NodeSysinfoRequest::success);
    connect(this->request, &JsonRequest::error, this, &NodeSysinfoRequest::error);
}

NodeSysinfoRequest::~NodeSysinfoRequest() {
    delete this->request;
}

void NodeSysinfoRequest::run() {
    if (this->retryCount > 0) {
        this->retryCount--;
        this->request->run();
    }
}

void NodeSysinfoRequest::success(QJsonDocument doc) {
    if (doc.isObject()) {
        QJsonObject json = doc.object();
        if (json.contains("version") && json.contains("data")) {
            this->n->fill(new DataParserSysinfo(json.value("data").toObject(), json.value("verison").toInt(-1)));
        }
    } else {
        std::cerr << "Node " << this->n->getId() << ": Not well formed JSON!" << std::endl;
    }    
}

void NodeSysinfoRequest::error(QString eStr) {
    this->n->setOnline(false);
    this->run();
}

