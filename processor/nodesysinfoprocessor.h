#ifndef NODESYSINFOPROCESSOR_H
#define NODESYSINFOPROCESSOR_H

#include "../JsonRequest.h"
#include "../Node.h"

#include <QJsonDocument>
#include <QObject>
#include <QRunnable>
#include <QString>


class NodeSysinfoProcessor : public QObject, public QRunnable
{
    Q_OBJECT

public:
    NodeSysinfoProcessor(Node* node);
    virtual ~NodeSysinfoProcessor();

    void run();

public slots:
    void success(QJsonDocument doc);
    void error(QString eStr);

signals:
    void finished(NodeSysinfoProcessor* processor);

private:
    Node* element;
    JsonRequest* request;
    int retryCount = 3;

    void runRequest();
};

#endif // NODESYSINFOPROCESSOR_H
