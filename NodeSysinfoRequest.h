
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
#include <QObject>
#include <QString>

#include <QNetworkReply>

class NodeSysinfoRequest : public QObject, public QRunnable {
    Q_OBJECT

public:
    NodeSysinfoRequest(Node* n);
    virtual ~NodeSysinfoRequest();

    void run();

public slots:
    void success(QJsonDocument doc);
    void error(QNetworkReply::NetworkError error, QString eStr);

private:
    Node* n;
    JsonRequest* request;
    int retryCount = 3;
};

#endif /* NODESYSINFOREQUEST_H */

