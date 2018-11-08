
/* 
 * File:   DataHolder.h
 * Author: NMerkelt
 *
 * Created on 17. Oktober 2018, 15:45
 */

#ifndef DATAHOLDER_H
#define DATAHOLDER_H

#include "JsonRequest.h"
#include "Node.h"

#include <QJsonDocument>
#include <QMap>
#include <QObject>
#include <QString>

class DataHolder : public QObject {
    Q_OBJECT

public:
    DataHolder();
    virtual ~DataHolder();

    Node* getNode(int id);
    Link* getLink(int node1, int node2);
    void addLink(Link* l);
    QMap<int, Node*> getNodes();
    QMap<int, QMap<int, Link*>*> getLinks();

    void requestAPI();

public slots:
    void processAPI(QJsonDocument doc);
    void processAPIError(QString eStr);

signals:
    void processedAPI(bool error);
    
private:
    QMap<int, Node*> nodes;
    QMap<int, QMap<int, Link*>*> links;
    JsonRequest* apiRequest;
};

#endif /* DATAHOLDER_H */

