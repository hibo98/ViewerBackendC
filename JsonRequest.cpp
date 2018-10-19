
/* 
 * File:   JsonRequest.cpp
 * Author: NMerkelt
 * 
 * Created on 18. Oktober 2018, 17:25
 */

#include "JsonRequest.h"

#include <iostream>
#include <QNetworkReply>
#include <QString>
#include <QJsonDocument>

JsonRequest::JsonRequest(QUrl* url, QObject* parent) : QObject(parent) {
    this->url = url;
    this->thread = new QThread();
    this->moveToThread(this->thread);
    connect(this->thread, &QThread::finished, this, &JsonRequest::deleteLater);
    connect(this, &JsonRequest::destroyed, this->thread, &QThread::deleteLater);
    connect(this->thread, &QThread::started, this, &JsonRequest::process);
}

void JsonRequest::start() {
    this->thread->start();
}

void JsonRequest::process() {
    this->manager = new QNetworkAccessManager();
    connect(this->manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                std::cerr << reply->errorString().toStdString() << std::endl;
                return;
            }

            QString answer = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(answer.toUtf8());
            emit result(doc);
        }
    );
    
    this->request.setUrl(*this->url);
    this->manager->get(this->request);
}

