
/* 
 * File:   Main2.cpp
 * Author: NMerkelt
 * 
 * Created on 13. Oktober 2018, 14:46
 */

#include "DataGen.h"
#include "Node.h"
#include "NodeSysinfoRequest.h"
#include "JsonFileGen.h"
#include "NodeProcessor.h"

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
    if (!error) {
        this->processNodes();
        this->collectLinks();
        this->genJson();
    }
    this->stop();
}

void DataGen::processNodes() {
    std::cout << "Requesting Nodes Sysinfo..." << std::endl;
    QList<Node*> values = DataGen::dh->getNodes().values();
    NodeProcessor proc(values);
    proc.process();
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

void DataGen::genJson() {
    std::cout << "Generate JSON files..." << std::endl;
    JsonFileGen json(DataGen::dh->getNodes().values(), DataGen::dh->getLinks().values());
    json.genHopGlass();
    json.genMeshViewer();
}

DataHolder* DataGen::getDataHolder() {
    return DataGen::dh;
}

void DataGen::stop() {
    delete DataGen::dh;
    QCoreApplication::instance()->quit();
}

