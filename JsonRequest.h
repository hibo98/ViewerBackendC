#ifndef JSONREQUEST_H
#define JSONREQUEST_H

#include <QJsonDocument>
#include <QObject>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class JsonRequest : public QObject {
    Q_OBJECT

public:
    explicit JsonRequest(QUrl url);
    virtual ~JsonRequest();

    void run();

private:
    QUrl url;
    static QNetworkAccessManager* manager;
    QNetworkReply* reply;
    bool hasError = false;

private slots:
    void finished();
    void replyError(QNetworkReply::NetworkError e);

signals:
    void result(QJsonDocument doc);
    void error(QString eStr);
    void queueDelete();
};

#endif /* JSONREQUEST_H */

