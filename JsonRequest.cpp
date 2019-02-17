#include "JsonRequest.h"

#include <QNetworkRequest>
#include <QString>
#include <QTimer>
#include <utility>
#include <iostream>

QNetworkAccessManager* JsonRequest::manager = new QNetworkAccessManager();

JsonRequest::JsonRequest(QUrl url) : QObject(nullptr) {
    this->url = std::move(url);
}

JsonRequest::~JsonRequest() = default;

void JsonRequest::run() {
    this->reply = JsonRequest::manager->get(QNetworkRequest(this->url));
    QObject::connect(this->reply, &QNetworkReply::finished, this, &JsonRequest::finished);
    QObject::connect(this->reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(replyError(QNetworkReply::NetworkError)));
    QTimer::singleShot(7500, this->reply, &QNetworkReply::abort);
}

void JsonRequest::finished() {
    if (!hasError && this->reply->error() == QNetworkReply::NoError) {
        QString answer = this->reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(answer.toUtf8());
        if (!doc.isNull() && !doc.isEmpty()) {
            emit result(doc);
        } else {
            emit error("Empty document");
        }
        emit queueDelete();
    }
}

void JsonRequest::replyError(QNetworkReply::NetworkError) {
    hasError = true;
    if (this->reply->error() == QNetworkReply::OperationCanceledError) {
        emit error("Connection timed out");
    } else {
        emit error(this->reply->errorString());
    }
    emit queueDelete();
}
