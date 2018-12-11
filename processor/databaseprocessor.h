#ifndef NODEPROCESSOR_H
#define NODEPROCESSOR_H

#include "nodedatabaseprocessor.h"
#include "../Node.h"

#include <QList>
#include <QObject>
#include <QQueue>
#include <QThreadPool>

class DatabaseProcessor : public QObject
{
  Q_OBJECT
public:
   DatabaseProcessor(QList<Node*> nodes);
   virtual ~DatabaseProcessor();

   void process();
   void processNode(Node* n);

public slots:
   void requestFinished(NodeDatabaseProcessor* proc);

signals:
   void queueEmpty();

private:
   QThreadPool pool;
   QQueue<Node*> queue;
   QList<NodeDatabaseProcessor*> processing;
};

#endif // NODEPROCESSOR_H
