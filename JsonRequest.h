
/* 
 * File:   JsonRequest.h
 * Author: NMerkelt
 *
 * Created on 18. Oktober 2018, 17:25
 */

#ifndef JSONREQUEST_H
#define JSONREQUEST_H

#include <QJsonDocument>
#include <QObject>
#include <QRunnable>
#include <QUrl>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class JsonRequest : public QObject, public QRunnable {
    Q_OBJECT

public:
    explicit JsonRequest(QUrl* url);
    void run();
private:
    QUrl* url;
    QNetworkAccessManager* manager;
    QNetworkRequest request;

signals:
    void result(QJsonDocument doc);
    void error(QNetworkReply::NetworkError error, QString eStr);
};

#endif /* JSONREQUEST_H */

