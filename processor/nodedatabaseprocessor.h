#ifndef NODESYSINFOPROCESSOR_H
#define NODESYSINFOPROCESSOR_H

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

private:
    Node* element;
};

#endif // NODESYSINFOPROCESSOR_H
