#include "JsonRequest.h"

#include <QString>
#include <QTimer>

JsonRequest::JsonRequest(QUrl url) : QObject(nullptr) {
    this->url = url;
}

JsonRequest::~JsonRequest() {
    delete this->manager;
    delete this->reply;
}

void JsonRequest::run() {
    QTimer* timer = new QTimer();
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &JsonRequest::timeout);
    this->manager = new QNetworkAccessManager();
    this->request.setUrl(this->url);
    this->reply = this->manager->get(this->request);
    QObject::connect(this->reply, &QNetworkReply::finished, this, &JsonRequest::finished);
    QObject::connect(this->reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(replyError(QNetworkReply::NetworkError)));
    timer->start(7500);
}

void JsonRequest::finished() {
    if (!reply->error()) {
        QString answer = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(answer.toUtf8());
        if (!doc.isNull() && !doc.isEmpty()) {
            emit result(doc);
        } else {
            emit error("Empty document");
        }
    } else {
        emit error(reply->errorString());
    }
}

void JsonRequest::replyError(QNetworkReply::NetworkError e) {
    emit error(this->reply->errorString());
}

void JsonRequest::timeout() {
    emit error("Connection timed out");
}
