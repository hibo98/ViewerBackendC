#include "DataGen.h"
#include "Node.h"
#include "JsonFileGen.h"
#include "processor/nodeprocessor.h"

#include <iostream>
#include <QCoreApplication>
#include <QList>
#include <QThreadPool>

#include <dataparser/DataParserDB.h>

DataHolder* DataGen::dh = nullptr;
MySQL* DataGen::db = nullptr;

DataGen::DataGen(QObject*parent) : QObject(parent) {
    DataGen::dh = new DataHolder();
}

void DataGen::start() {
    std::cout << "Welcome to ViewerBackend" << std::endl;
    std::cout << "Connecting to Database..." << std::endl;
    DataGen::db = new MySQL();
    if (!DataGen::db->hasConnection()) {
        std::cerr << "Database Connection couldn't be established!" << std::endl;
        this->stop();
    } else {
        std::cout << "Requesting API..." << std::endl;
        QObject::connect(dh, &DataHolder::processedAPI, this, &DataGen::processedAPI);
        DataGen::dh->requestAPI();
    }
}

void DataGen::processedAPI(bool error) {
    if (!error) {
        this->processNodes();
        this->fillOfflineNodes();
        this->collectLinks();
        this->genJson();
        this->saveToDatabase();
    }
    this->stop();
}

void DataGen::processNodes() {
    std::cout << "Requesting Nodes Sysinfo..." << std::endl;
    QList<Node*> values = DataGen::dh->getNodes().values();
    NodeProcessor proc(values);
    proc.process();
}

void DataGen::fillOfflineNodes()
{
    std::cout << "Fill offline nodes from database..." << std::endl;
    QString ids;
    QList<Node*> nodes = DataGen::dh->getNodes().values();
    for (int i = 0; i < nodes.size(); i++) {
        Node* node = nodes.at(i);
        if (!node->isOnline()) {
            QString s = QString(std::to_string(node->getId()).c_str());
            ids = ids.append(s).append(",");
        }
    }
    ids.resize(ids.length() - 1);
    if (ids.isEmpty()) {
        return;
    }
    sql::ResultSet* rs = DataGen::db->executeQuery("SELECT * FROM nodes WHERE id IN (" + ids.toStdString() + ")");
    while (rs->next()) {
        DataGen::dh->getNode(rs->getInt("id"))->fill(new DataParserDB(rs));
    }
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

void DataGen::saveToDatabase()
{
    std::cout << "Saving to database..." << std::endl;
    //TODO: Saving to Database
}

DataHolder* DataGen::getDataHolder() {
    return DataGen::dh;
}

MySQL* DataGen::getDatabase()
{
    return DataGen::db;
}

void DataGen::stop() {
    delete DataGen::dh;
    QCoreApplication::instance()->quit();
}

