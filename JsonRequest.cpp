
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

JsonRequest::JsonRequest(QUrl* url) : QObject(nullptr) {
    this->url = url;
}

void JsonRequest::run() {
    this->manager = new QNetworkAccessManager();
    connect(this->manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply* reply) {
            QNetworkReply::NetworkError e = reply->error();
            if (e == QNetworkReply::NoError) {
                QString answer = reply->readAll();
                QJsonDocument doc = QJsonDocument::fromJson(answer.toUtf8());
                emit result(doc);
            } else {
                emit error(reply->errorString());
            }
            delete this->url;
            delete reply;
            delete this->manager;
        }
    );
    
    this->request.setUrl(*this->url);
    this->manager->get(this->request);
}

