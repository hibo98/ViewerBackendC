#ifndef DATAHOLDER_H
#define DATAHOLDER_H

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
    void processAPI(const QJsonDocument& doc);
    void processAPIError(const QString& eStr);

signals:
    void processedAPI(bool error);
    
private:
    QMap<int, Node*> nodes;
    QMap<int, QMap<int, Link*>*> links;
};

#endif /* DATAHOLDER_H */

