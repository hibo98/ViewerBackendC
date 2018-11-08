
/* 
 * File:   NodeProcessor.h
 * Author: NMerkelt
 *
 * Created on 6. November 2018, 11:14
 */

#ifndef NODEPROCESSOR_H
#define NODEPROCESSOR_H

#include "Node.h"
#include "NodeSysinfoRequest.h"

#include <QList>
#include <QObject>
#include <QQueue>

class NodeProcessor : public QObject {
    Q_OBJECT

public:
    NodeProcessor(QList<Node*> nodes);
    virtual ~NodeProcessor();

    void process();
    void processNode(Node* n);

public slots:
    void requestFinished(NodeSysinfoRequest* n);

signals:
    void queueEmpty();

private:
    QQueue<Node*> queue;
    QList<NodeSysinfoRequest*> processing;
};

#endif /* NODEPROCESSOR_H */

