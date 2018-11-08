
/* 
 * File:   NodeSysinfoRequest.h
 * Author: NMerkelt
 *
 * Created on 22. Oktober 2018, 18:15
 */

#ifndef NODESYSINFOREQUEST_H
#define NODESYSINFOREQUEST_H

#include "JsonRequest.h"
#include "Node.h"

#include <QJsonDocument>
#include <QRunnable>
#include <QObject>
#include <QString>

class NodeSysinfoRequest : public QObject, public QRunnable {
    Q_OBJECT

public:
    NodeSysinfoRequest(Node* n);
    virtual ~NodeSysinfoRequest();

    void run();

public slots:
    void success(QJsonDocument doc);
    void error(QString eStr);

signals:
    void finished(NodeSysinfoRequest* n);

private:
    Node* n;
    JsonRequest* request;
    int retryCount = 3;

    void runRequest();
};

#endif /* NODESYSINFOREQUEST_H */

