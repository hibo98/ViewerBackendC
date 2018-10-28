
/* 
 * File:   DataHolder.cpp
 * Author: NMerkelt
 * 
 * Created on 17. Oktober 2018, 15:45
 */

#include "DataHolder.h"
#include "JsonRequest.h"
#include "dataparser/DataParserAPI.h"

#include <algorithm>
#include <iostream>
#include <QJsonArray>
#include <QThreadPool>

DataHolder::DataHolder() : QObject(nullptr){
}

DataHolder::~DataHolder() {
}

Node* DataHolder::getNode(int id) {
    Node* n = this->nodes.value(id, new Node(id));
    if (!this->nodes.contains(id)) {
        this->nodes.insert(id, n);
    }
    return n;
}

Link* DataHolder::getLink(int node1, int node2) {
    int min = std::min(node1, node2);
    int max = std::max(node1, node2);
    if (!this->links.contains(min)) {
        return nullptr;
    } else {
        return this->links.value(min)->value(max, nullptr);
    }
}

void DataHolder::addLink(Link* l) {
    int min = std::min(l->getSource()->getId(), l->getTarget()->getId());
    int max = std::max(l->getSource()->getId(), l->getTarget()->getId());
    if (!this->links.contains(min)) {
        this->links.insert(min, new QMap<int, Link*>());
    }
    this->links.value(min)->insert(max, l);
}

QMap<int, Node*> DataHolder::getNodes() {
    return this->nodes;
}

QMap<int, QMap<int, Link*>*> DataHolder::getLinks() {
    return this->links;
}

void DataHolder::requestAPI() {
    JsonRequest* request = new JsonRequest(new QUrl("http://api.freifunk-dresden.de/freifunk-niklas-hopglass.json"));
    connect(request, &JsonRequest::result, this, &DataHolder::processAPI);
    connect(request, &JsonRequest::error, this, &DataHolder::processAPIError);
    request->run();
}

void DataHolder::processAPI(QJsonDocument doc) {
    if (!doc.isArray()) {
        std::cerr << "No Array!" << std::endl;
        return;
    }
    QJsonArray array = doc.array();
    for (int i = 0; i < array.size(); i++) {
        QJsonValueRef value = array[i];
        if (value.isObject()) {
            QJsonObject o = value.toObject();
            int id = o.value("id").toString("-1").toInt();
            if (id != -1) {
                this->getNode(id)->fill(new DataParserAPI(o));
            }
        }
    }
    emit processedAPI(false);
}

void DataHolder::processAPIError(QString eStr) {
    std::cerr << eStr.toStdString() << std::endl;
    emit processedAPI(true);
}

