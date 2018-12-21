#ifndef NODEPROCESSOR_H
#define NODEPROCESSOR_H

#include "nodesysinfoprocessor.h"
#include "../Node.h"

#include <QList>
#include <QObject>
#include <QQueue>

class NodeProcessor : public QObject
{
  Q_OBJECT
public:
   NodeProcessor(const QList<Node*>& nodes);
   virtual ~NodeProcessor();

   void process();
   void processNode(Node* n);

public slots:
   void requestFinished(NodeSysinfoProcessor* proc);

signals:
   void queueEmpty();

private:
   QQueue<Node*> queue;
   QList<NodeSysinfoProcessor*> processing;
};

#endif // NODEPROCESSOR_H
