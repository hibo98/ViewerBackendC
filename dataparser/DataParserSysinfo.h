
/* 
 * File:   DataParserSysinfo.h
 * Author: NMerkelt
 *
 * Created on 19. Oktober 2018, 19:46
 */

#ifndef DATAPARSERSYSINFO_H
#define DATAPARSERSYSINFO_H

#include "DataParser.h"

#include "Node.h"

#include <QJsonObject>
#include <QSet>

class DataParserSysinfo : public DataParser {
public:
    DataParserSysinfo(QJsonObject json, int version);
    DataParserSysinfo(const DataParserSysinfo& orig);
    virtual ~DataParserSysinfo();
    
    QJsonObject getData() override;
    bool hasLinkSet() override;
    void getLinkSet(QSet<Link*>*) override;
private:
    QJsonObject data;
    QJsonObject r;
    int version;
    QJsonObject stats;
    
    int getNodeId();
    
    bool getAutoUpdate();
    int getClients();
    QString getCommunity();
    QString getEMail();
    QString getFirmwareBase();
    QString getFirmwareVersion();
    QString getGatewayIp();
    long getLastseen();
    double getLoadAvg();
    double getLongitude();
    double getLatitude();
    double getMemoryUsage();
    QString getModel();
    QString getName();
    NodeType getRole();
    double getUptime();
    bool isOnline();
    
    static int parseMinutes(QString time);
};

#endif /* DATAPARSERSYSINFO_H */

