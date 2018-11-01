
/* 
 * File:   Node.h
 * Author: NMerkelt
 *
 * Created on 17. Oktober 2018, 13:11
 */

#ifndef NODE_H
#define NODE_H

#include "Link.h"
#include "Location.h"
#include "dataparser/DataParser.h"

#include <QJsonObject>
#include <QString>
#include <QSet>

enum NodeType {
    STANDARD
};

class Node {
public:
    Node(int id);
    Node(const Node& orig);
    virtual ~Node();

    QString getHostname();
    QString getFakeMac();
    QString getIpAddress(bool subnet201 = false);
    QString getNodeType();
    
    int getId();
    QSet<Link*> getLinks();
    signed char getClients();
    
    bool isValid();
    bool isDisplayed();
    bool isOnline();
    
    bool hasValidLocation();
    
    void fill(DataParser* dp);
    
    QJsonObject* getJsonObjectHop();
    QJsonObject* getJsonObjectMesh();
    
    void setOnline(bool online);
    
    static int convertIpToId(QString ip);
    
private:
    int id = -1;
    QSet<Link*> links;
    QString name;
    QString community;
    NodeType type = STANDARD;
    QString model;
    QString firmwareVersion;
    QString firmwareBase;
    QString email;
    bool online;
    double uptime;
    double memoryUsage;
    signed char clients;
    double avgLoad;
    bool gateway;
    long lastseen = -1;
    long firstseen = -1;
    Location* location;
    QString gatewayIp;
    bool valid = false;
    bool display;
    bool autoupdate;
};

#endif /* NODE_H */

