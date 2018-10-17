
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
    
    int getId();
    QSet<Link*> getLinks();
    signed char getClients();
    
    bool isValid();
    bool isDisplayed();
    bool isOnline();
    
    bool hasValidLocation();
    
    static int convertIpToId(QString ip);
    static QString convertIdToMac(int id);
    static QString convertIdToIp(int id);
    static QString convertIdToIp(int id, bool subnet201);
    
private:
    int id = -1;
    QSet<Link*> links;
    QString name;
    QString community;
    NodeType type;
    QString model;
    QString firmwareVersion;
    QString firmwareBase;
    QString email;
    bool online;
    float uptime;
    float memoryUsage;
    signed char clients;
    float avgLoad;
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

