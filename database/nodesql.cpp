#include "nodesql.h"
#include "../DataGen.h"

QList<Node*> NodeSQL::nodes = QList<Node*>();

void NodeSQL::addNode(Node* node)
{
    NodeSQL::nodes.append(node);
}

void NodeSQL::processNodes()
{
    QSqlQuery ps1 = DataGen::getDatabase()->prepareStatement("INSERT INTO nodes SET id = ? ON DUPLICATE KEY UPDATE id = id");
    QSqlQuery ps2 = DataGen::getDatabase()->prepareStatement("INSERT INTO nodes (id, latitude, longitude) VALUES (?, ?, ?) ON DUPLICATE KEY UPDATE latitude = VALUES(latitude), longitude = VALUES(longitude)");
    QSqlQuery ps3 = DataGen::getDatabase()->prepareStatement("UPDATE nodes SET community = ?, role = ?, model = ?, firmwareVersion = ?, firmwareBase = ?, firstseen = ?, lastseen = ?, online = ?, autoupdate = ?, gateway = ?, name = ?, email = ? WHERE id = ?");
    for (int i = 0; i < NodeSQL::nodes.size(); i++) {
        Node* node = NodeSQL::nodes.at(i);
        if (!node->hasValidLocation()) {
            ps1.addBindValue(node->getId());
            DataGen::getDatabase()->execPS(ps1);
        } else {
            ps2.addBindValue(node->getId());
            ps2.addBindValue(node->getLocation()->getLatitude());
            ps2.addBindValue(node->getLocation()->getLongitude());
            DataGen::getDatabase()->execPS(ps2);
        }
        ps3.addBindValue(node->getCommunity());
        ps3.addBindValue(node->getNodeType());
        ps3.addBindValue(node->getModel());
        ps3.addBindValue(node->getFirmwareVersion());
        ps3.addBindValue(node->getFirmwareBase());
        ps3.addBindValue(node->getFirstseen() / 1000);
        ps3.addBindValue(node->getLastseen() / 1000);
        ps3.addBindValue(node->isOnline());
        ps3.addBindValue(node->isAutoupdate());
        ps3.addBindValue(node->isGateway());
        ps3.addBindValue(node->getName());
        ps3.addBindValue(node->getEMail());
        ps3.addBindValue(node->getId());
        DataGen::getDatabase()->execPS(ps3);
    }
}
