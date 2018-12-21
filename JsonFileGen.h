#ifndef JSONFILEGEN_H
#define JSONFILEGEN_H

#include "Link.h"
#include "Node.h"

#include <QJsonArray>
#include <QList>
#include <QMap>

class JsonFileGen {
public:
    JsonFileGen(const QList<Node*>& nodes, const QList<QMap<int, Link*>*>& links);
    JsonFileGen(const JsonFileGen& orig);
    virtual ~JsonFileGen();

    void genMeshViewer();
    void genHopGlass();
private:
    QJsonArray hopGlassNodes;
    QJsonArray graphNodes;
    QJsonArray graphLinks;
    QJsonArray meshViewerNodes;
    QJsonArray meshViewerLinks;
    QMap<Node*, int> nodeIds;
};

#endif /* JSONFILEGEN_H */

