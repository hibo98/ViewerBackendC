#include "JsonRequest.h"

#include <QString>

JsonRequest::JsonRequest(QUrl url) : QObject(nullptr) {
    this->url = url;
}

JsonRequest::~JsonRequest() {
    delete this->manager;
    delete this->timer;
}

void JsonRequest::run() {
    this->timer = new QTimer();
    this->timer->setSingleShot(true);
    connect(this->timer, &QTimer::timeout, this, &JsonRequest::timeout);
    this->manager = new QNetworkAccessManager();
    this->request.setUrl(this->url);
    this->reply = this->manager->get(this->request);
    QObject::connect(this->reply, &QNetworkReply::finished, this, &JsonRequest::finished);
    QObject::connect(this->reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(replyError(QNetworkReply::NetworkError)));
    this->timer->start(7500);
}

void JsonRequest::finished() {
    if (!this->reply->error()) {
        QString answer = this->reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(answer.toUtf8());
        if (!doc.isNull() && !doc.isEmpty()) {
            emit result(doc);
        } else {
            emit error("Empty document");
        }
    } else {
        emit error(this->reply->errorString());
    }
}

void JsonRequest::replyError(QNetworkReply::NetworkError) {
    emit error(this->reply->errorString());
}

void JsonRequest::timeout() {
    emit error("Connection timed out");
}
