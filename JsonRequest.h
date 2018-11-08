
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
#include <QUrl>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class JsonRequest : public QObject {
    Q_OBJECT

public:
    explicit JsonRequest(QUrl url);
    virtual ~JsonRequest();

    void run();

private:
    QUrl url;
    QNetworkAccessManager* manager;
    QNetworkRequest request;
    QNetworkReply* reply;

private slots:
    void finished();
    void replyError(QNetworkReply::NetworkError e);
    void timeout();

signals:
    void result(QJsonDocument doc);
    void error(QString eStr);
};

#endif /* JSONREQUEST_H */

