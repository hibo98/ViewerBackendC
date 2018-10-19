
/* 
 * File:   JsonRequest.h
 * Author: NMerkelt
 *
 * Created on 18. Oktober 2018, 17:25
 */

#ifndef JSONREQUEST_H
#define JSONREQUEST_H

#include <QObject>
#include <QThread>
#include <QUrl>

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

class JsonRequest : public QObject {

    Q_OBJECT

public:
    explicit JsonRequest(QUrl* url, QObject* parent = nullptr);
    void start();
private:
    QThread* thread;
    QUrl* url;
    QNetworkAccessManager* manager;
    QNetworkRequest request;
private slots:
    void process();
    
signals:
    void result(QJsonDocument doc);
};

#endif /* JSONREQUEST_H */

