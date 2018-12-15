#ifndef NODEDATABASEPROCESSOR_H
#define NODEDATABASEPROCESSOR_H

#include "../JsonRequest.h"
#include "../Node.h"

#include <QThread>
#include <QObject>
#include <QRunnable>
#include <QString>


class NodeDatabaseProcessor : public QObject, public QRunnable
{
    Q_OBJECT

public:
    NodeDatabaseProcessor(Node* node);
    virtual ~NodeDatabaseProcessor();

    void run();

public slots:
    void finish();

signals:
    void finished(NodeDatabaseProcessor* processor);
    void done();

private:
    Node* element;
};

#endif // NODEDATABASEPROCESSOR_H
