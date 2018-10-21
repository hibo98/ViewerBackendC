
/* 
 * File:   DataParser.h
 * Author: NMerkelt
 *
 * Created on 18. Oktober 2018, 22:24
 */

#ifndef DATAPARSER_H
#define DATAPARSER_H

#include "Link.h"

#include <QJsonObject>
#include <QSet>
#include <QString>

class DataParser {
public:
    virtual QJsonObject getData();
    virtual bool hasLinkSet();
    virtual void getLinkSet(QSet<Link*>*);
/*private:
    bool getAutoUpdate();
    signed short getClients();
    QString getCommunity();
    QString getEMail();
    QString getFirmwareBase();
    QString getFirmwareVersion();
    long getFirstseen();
    QString getGatewayIp();
    long getLastseen();
    float getLoadAvg();
    Location getLocation();
    float getMemoryUsage();
    QString getModel();
    QString getName();
    NodeType getRole();
    float getUptime();
    bool isOnline();
    bool isGateway();*/
};

#endif /* DATAPARSER_H */

