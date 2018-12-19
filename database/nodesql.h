#ifndef NODESQL_H
#define NODESQL_H

#include "../Node.h"

#include <QList>

class NodeSQL
{
public:
    static void addNode(Node* n);

    static void processNodes();

private:
    static QList<Node*> nodes;
};

#endif // NODESQL_H
