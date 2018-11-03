
/* 
 * File:   JsonRequest.cpp
 * Author: NMerkelt
 * 
 * Created on 18. Oktober 2018, 17:25
 */

#include "JsonRequest.h"

#include <iostream>
#include <QString>

#include <QNetworkReply>

JsonRequest::JsonRequest(QUrl url) : QObject(nullptr) {
    this->url = url;
}

JsonRequest::~JsonRequest() {
    if (this->manager != nullptr) {
        delete this->manager;
    }
}

void JsonRequest::run() {
    this->manager = new QNetworkAccessManager();
    this->request.setUrl(this->url);
    this->reply = this->manager->get(this->request);
    QObject::connect(this->reply, &QNetworkReply::finished, this, &JsonRequest::finished);
    QObject::connect(this->reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error), this, &JsonRequest::replyError);
}

void JsonRequest::finished() {
    QNetworkReply::NetworkError e = reply->error();
    if (e == QNetworkReply::NoError) {
        QString answer = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(answer.toUtf8());
        emit result(doc);
    } else {
        emit error(reply->errorString());
    }
}

void JsonRequest::replyError(QNetworkReply::NetworkError e) {
    emit error(this->reply->errorString());
}
