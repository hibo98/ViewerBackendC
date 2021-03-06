#ifndef DATAPARSERDB_H
#define DATAPARSERDB_H

#include "DataParser.h"
#include "Node.h"

#include <QJsonObject>
#include <QSet>
#include <QString>
#include <QSqlQuery>

class DataParserDB : public DataParser
{
public:
    DataParserDB(const QSqlQuery& result);
    DataParserDB(const DataParserDB& orig);
    virtual ~DataParserDB() override;

    QJsonObject getData() override;
    bool hasLinkSet() override;
    void getLinkSet(QSet<Link*>*) override;

private:
    QSqlQuery result;
    QJsonObject r;
    bool getAutoUpdate();
    QString getCommunity();
    QString getEMail();
    QString getFirmwareBase();
    QString getFirmwareVersion();
    long long getFirstseen();
    long long getLastseen();
    double getLongitude();
    double getLatitude();
    QString getModel();
    QString getName();
    NodeType getRole();
    bool isGateway();
    bool isOnline();
};

#endif // DATAPARSERDB_H
