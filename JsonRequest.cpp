#include "JsonRequest.h"

#include <QString>
#include <QTimer>
#include <utility>

QNetworkAccessManager* JsonRequest::manager = new QNetworkAccessManager();

JsonRequest::JsonRequest(QUrl url) : QObject(nullptr) {
    this->url = std::move(url);
}

JsonRequest::~JsonRequest() = default;

void JsonRequest::run() {
    this->request.setUrl(this->url);
    this->reply = JsonRequest::manager->get(this->request);
    QObject::connect(this->reply, &QNetworkReply::finished, this, &JsonRequest::finished);
    QObject::connect(this->reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(replyError(QNetworkReply::NetworkError)));
    QTimer::singleShot(7500, this, &JsonRequest::timeout);
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
