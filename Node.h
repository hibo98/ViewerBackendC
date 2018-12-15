#ifndef NODE_H
#define NODE_H

#include "Link.h"
#include "Location.h"
#include "dataparser/DataParser.h"

#include <QJsonObject>
#include <QString>
#include <QSet>

enum NodeType
{
    STANDARD
};

class Node
{
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
    short getClients();
    
    bool isValid();
    bool isDisplayed();
    bool isOnline();
    
    bool hasValidLocation();
    
    void fill(DataParser* dp);
    void updateDatabase();
    
    QJsonObject getJsonObjectHop();
    QJsonObject getJsonObjectMesh();
    
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
    short clients;
    double avgLoad;
    bool gateway;
    long long lastseen = -1;
    long long firstseen = -1;
    Location* location = nullptr;
    QString gatewayIp;
    bool valid = false;
    bool autoupdate;
};

#endif /* NODE_H */

