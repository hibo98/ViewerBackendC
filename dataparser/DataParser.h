#ifndef DATAPARSER_H
#define DATAPARSER_H

#include "Link.h"

#include <QJsonObject>
#include <QSet>
#include <QString>

class DataParser {
public:
    virtual ~DataParser();
    virtual QJsonObject getData() = 0;
    virtual bool hasLinkSet() = 0;
    virtual void getLinkSet(QSet<Link*>*) = 0;
};

#endif /* DATAPARSER_H */

