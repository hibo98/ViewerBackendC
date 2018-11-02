
/* 
 * File:   Main2.cpp
 * Author: NMerkelt
 * 
 * Created on 13. Oktober 2018, 14:46
 */

#include "DataGen.h"
#include "Node.h"
#include "NodeSysinfoRequest.h"

#include <iostream>
#include <QCoreApplication>
#include <QList>
#include <QThreadPool>

DataHolder* DataGen::dh = nullptr;

DataGen::DataGen(QObject*parent) : QObject(parent) {
    DataGen::dh = new DataHolder();
}

void DataGen::start() {
    std::cout << "Welcome to ViewerBackend" << std::endl;
    std::cout << "Requesting API..." << std::endl;
    QObject::connect(dh, &DataHolder::processedAPI, this, &DataGen::processedAPI);
    DataGen::dh->requestAPI();
}

void DataGen::processedAPI(bool error) {
    if (error) {
        this->stop();
    } else {
        this->processNodes();
        this->collectLinks();
    }
}

void DataGen::processNodes() {
    std::cout << "Requesting Nodes Sysinfo..." << std::endl;
    QList<Node*> values = DataGen::dh->getNodes().values();
    QThreadPool pool;
    for (int i = 0; i < values.size(); i++) {
        Node* node = values.at(i);
        NodeSysinfoRequest* request = new NodeSysinfoRequest(node);
        pool.start(request);
    }
    pool.waitForDone();
}

void DataGen::collectLinks() {
    std::cout << "Collecting links..." << std::endl;
    QList<Node*> values = DataGen::dh->getNodes().values();
    for (int i = 0; i < values.size(); i++) {
        Node* node = values.at(i);
        QList<Link*> links = node->getLinks().values();
        for (int j = 0; j < links.size(); j++) {
            Link* link = links.at(j);
            Link* lnk = DataGen::dh->getLink(link->getSource()->getId(), link->getTarget()->getId());
            if (lnk == nullptr) {
                DataGen::dh->addLink(link);
            } else {
                lnk->setTargetTq(link->getSourceTq());
            }
        }
    }
}

DataHolder* DataGen::getDataHolder() {
    return DataGen::dh;
}

void DataGen::stop() {
    QCoreApplication::instance()->quit();
}

