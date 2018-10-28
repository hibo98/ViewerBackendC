
/* 
 * File:   Main2.cpp
 * Author: NMerkelt
 * 
 * Created on 13. Oktober 2018, 14:46
 */

#include "DataGen.h"
#include "Node.h"
#include "NodeSysinfoRequest.h"

#include <QCoreApplication>
#include <QList>
#include <QThreadPool>

DataHolder* DataGen::dh = nullptr;

DataGen::DataGen(QObject*parent) : QObject(parent) {
    DataGen::dh = new DataHolder();
}

void DataGen::start() {
    QObject::connect(dh, &DataHolder::processedAPI, this, &DataGen::processedAPI);
    DataGen::dh->requestAPI();
}

void DataGen::processedAPI(bool error) {
    if (error) {
        this->stop();
    } else {
        this->processNodes();
    }
}

void DataGen::processNodes() {
    QList<Node*> values = DataGen::dh->getNodes().values();
    QThreadPool pool;
    for (int i = 0; i < values.size(); i++) {
        Node* node = values.at(i);
        NodeSysinfoRequest* request = new NodeSysinfoRequest(node);
        pool.start(request);
    }
}

DataHolder* DataGen::getDataHolder() {
    return DataGen::dh;
}

void DataGen::stop() {
    QCoreApplication::instance()->quit();
}

