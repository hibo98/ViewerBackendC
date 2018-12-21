#include "JsonFileGen.h"
#include "Node.h"
#include "Util.h"

#include <iostream>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QString>

JsonFileGen::JsonFileGen(const QList<Node*>& nodes, const QList<QMap<int, Link*>*>& links) {
    for (int i = 0; i < nodes.size(); i++) {
        Node* node = nodes.at(i);
        if (!node->isDisplayed()) {
            continue;
        }
        this->hopGlassNodes.append(QJsonValue(node->getJsonObjectHop()));
        this->meshViewerNodes.append(QJsonValue(node->getJsonObjectMesh()));
        QJsonObject jsonNode;
        jsonNode.insert("node_id", QJsonValue(QString::number(node->getId())));
        jsonNode.insert("id", QJsonValue(QString::number(node->getId())));
        jsonNode.insert("seq", QJsonValue(i));
        this->graphNodes.append(QJsonValue(jsonNode));
        this->nodeIds.insert(node, i);
    }
    for (QMap<int, Link*>* i : links) {
        QList<Link*> linkl = i->values();
        for (Link* link : linkl) {
            if (!link->getSource()->isDisplayed() ||
                    !link->getTarget()->isDisplayed() ||
                    !link->getSource()->isOnline() ||
                    !link->getTarget()->isOnline()) {
                continue;
            }
            //MeshViewer
            QJsonObject linkM;
            linkM.insert("source", QJsonValue(QString::number(link->getSource()->getId())));
            linkM.insert("target", QJsonValue(QString::number(link->getTarget()->getId())));
            linkM.insert("source_tq", QJsonValue(Link::convertToMeshViewer(link->getSourceTq())));
            linkM.insert("target_tq", QJsonValue(Link::convertToMeshViewer(link->getTargetTq())));
            linkM.insert("type", QJsonValue(link->getTypeMeshViewer()));
            linkM.insert("source_addr", QJsonValue(link->getSource()->getFakeMac()));
            linkM.insert("target_addr", QJsonValue(link->getTarget()->getFakeMac()));
            this->meshViewerLinks.append(linkM);
            //HopGlass
            int source = nodeIds.value(link->getSource());
            int target = nodeIds.value(link->getTarget());
            QJsonObject linkH;
            linkH.insert("source", QJsonValue(source));
            linkH.insert("target", QJsonValue(target));
            linkH.insert("tq", Link::convertToHopGlass(link->getSourceTq()));
            linkH.insert("type", QJsonValue(link->getTypeHopglass()));
            this->graphLinks.append(linkH);
            if (link->getTargetTq() != -1) {
                linkH = QJsonObject();
                linkH.insert("source", QJsonValue(target));
                linkH.insert("target", QJsonValue(source));
                linkH.insert("tq", Link::convertToHopGlass(link->getTargetTq()));
                linkH.insert("type", QJsonValue(link->getTypeHopglass()));
                this->graphLinks.append(linkH);
            }
        }
    }
}

JsonFileGen::JsonFileGen(const JsonFileGen& orig) {
    this->hopGlassNodes = orig.hopGlassNodes;
    this->graphNodes = orig.graphNodes;
    this->graphLinks = orig.graphLinks;
    this->meshViewerNodes = orig.meshViewerNodes;
    this->meshViewerLinks = orig.meshViewerLinks;
    this->nodeIds = orig.nodeIds;
}

JsonFileGen::~JsonFileGen() = default;

void JsonFileGen::genHopGlass() {
    //nodes.json
    QJsonObject jsonObject;
    jsonObject.insert("nodes", QJsonValue(this->hopGlassNodes));
    jsonObject.insert("timestamp", QJsonValue(Util::getTimeString(Util::getCurrentTimestamp())));
    jsonObject.insert("version", QJsonValue(2));
    QJsonDocument nodesDoc(jsonObject);
    QFile nodes("nodes.json");
    if (!nodes.open(QIODevice::WriteOnly)) {
        std::cerr << "Couldn't open file:" << "nodes.json" << std::endl;
        return;
    }
    nodes.write(nodesDoc.toJson(QJsonDocument::Compact));
    //graph.json
    jsonObject = QJsonObject();
    jsonObject.insert("version", QJsonValue(1));
    QJsonObject batadv;
    batadv.insert("multigraph", QJsonValue(false));
    batadv.insert("directed", QJsonValue(true));
    batadv.insert("graph", QJsonValue(QJsonArray()));
    batadv.insert("nodes", QJsonValue(this->graphNodes));
    batadv.insert("links", QJsonValue(this->graphLinks));
    jsonObject.insert("batadv", QJsonValue(batadv));
    QJsonDocument graphDoc(jsonObject);
    QFile graph("graph.json");
    if (!graph.open(QIODevice::WriteOnly)) {
        std::cerr << "Couldn't open file:" << "graph.json" << std::endl;
        return;
    }
    graph.write(graphDoc.toJson(QJsonDocument::Compact));
}

void JsonFileGen::genMeshViewer() {
    QJsonObject jsonObject;
    jsonObject.insert("timestamp", QJsonValue(Util::getTimeString(Util::getCurrentTimestamp())));
    jsonObject.insert("nodes", QJsonValue(this->meshViewerNodes));
    jsonObject.insert("links", QJsonValue(this->meshViewerLinks));
    QJsonDocument doc(jsonObject);
    QFile file("meshviewer.json");
    if (!file.open(QIODevice::WriteOnly)) {
        std::cerr << "Couldn't open file:" << "meshviewer.json" << std::endl;
        return;
    }
    file.write(doc.toJson(QJsonDocument::Compact));
}
