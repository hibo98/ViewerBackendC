#include "DataHolder.h"
#include "JsonRequest.h"
#include "dataparser/DataParserAPI.h"

#include <algorithm>
#include <iostream>
#include <QJsonArray>
#include <QThreadPool>
#include <QList>

DataHolder::DataHolder() : QObject(nullptr){
}

DataHolder::~DataHolder() {
    QList<QMap<int,Link*>*> links1 = this->links.values();
    for (QMap<int,Link*>* links2 : links1) {
        QList<Link*> values = links2->values();
        int min = -1;
        for (Link* link : values) {
            min = std::min(link->getSource()->getId(), link->getTarget()->getId());
            int max = std::max(link->getSource()->getId(), link->getTarget()->getId());
            links2->remove(max);
            delete link;
        }
        if (min != -1) {
            this->links.remove(min);
        }
        delete links2;
    }
    for (Node* node : this->nodes) {
        this->nodes.remove(node->getId());
        delete node;
    }
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
    }
    return this->links.value(min)->value(max, nullptr);
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
    auto apiRequest = new JsonRequest(QUrl("http://api.freifunk-dresden.de/freifunk-niklas-hopglass.json"));
    connect(apiRequest, &JsonRequest::result, this, &DataHolder::processAPI);
    connect(apiRequest, &JsonRequest::error, this, &DataHolder::processAPIError);
    connect(apiRequest, &JsonRequest::queueDelete, apiRequest, &JsonRequest::deleteLater);
    apiRequest->run();
}

void DataHolder::processAPI(const QJsonDocument& doc) {
    if (!doc.isArray()) {
        std::cerr << "No Array!" << std::endl;
        emit processedAPI(true);
        return;
    }
    QJsonArray array = doc.array();
    for (QJsonValue value : array) {
        if (value.isObject()) {
            QJsonObject o = value.toObject();
            int id = o.value("id").toString("-1").toInt();
            if (id != -1) {
                DataParserAPI* dp = new DataParserAPI(o);
                this->getNode(id)->fill(dp);
                delete dp;
            }
        }
    }
    emit processedAPI(false);
}

void DataHolder::processAPIError(const QString& eStr) {
    std::cerr << eStr.toStdString() << std::endl;
    emit processedAPI(true);
}

