
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
    virtual ~DataParser();
    virtual QJsonObject getData();
    virtual bool hasLinkSet();
    virtual void getLinkSet(QSet<Link*>*);
};

#endif /* DATAPARSER_H */

