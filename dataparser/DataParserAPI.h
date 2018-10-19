
/* 
 * File:   DataParserAPI.h
 * Author: NMerkelt
 *
 * Created on 18. Oktober 2018, 22:58
 */

#ifndef DATAPARSERAPI_H
#define DATAPARSERAPI_H

#include "DataParser.h"

#include <QJsonObject>
#include <QSet>

class DataParserAPI : public DataParser {
public:
    DataParserAPI(QJsonObject json);
    DataParserAPI(const DataParserAPI& orig);
    virtual ~DataParserAPI();
    
    QJsonObject getData() override;
    bool hasLinkSet() override;
    QSet<Link*>* getLinkSet() override;
private:
    QJsonObject json;
    int getClients();
    long getFirstseen();
    long getLastseen();
    float getLongitude();
    float getLatitude();
    bool isOnline();
    bool isGateway();
};

#endif /* DATAPARSERAPI_H */

