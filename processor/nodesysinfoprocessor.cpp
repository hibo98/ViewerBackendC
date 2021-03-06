#include "../JsonRequest.h"
#include "nodesysinfoprocessor.h"
#include "dataparser/DataParserSysinfo.h"

#include <iostream>

NodeSysinfoProcessor::NodeSysinfoProcessor(Node* element) : QObject(nullptr)
{
    this->element = element;
}

NodeSysinfoProcessor::~NodeSysinfoProcessor() = default;

void NodeSysinfoProcessor::run()
{
    this->runRequest();
}

void NodeSysinfoProcessor::success(const QJsonDocument& doc)
{
    if (doc.isObject()) {
        QJsonObject json = doc.object();
        if (json.contains("version") && json.contains("data")) {
            DataParserSysinfo* dp = new DataParserSysinfo(json.value("data").toObject(), json.value("verison").toInt(-1));
            this->element->fill(dp);
            delete dp;
        }
    } else {
        std::cerr << "Node " << this->element->getId() << ": Not well formed JSON!" << std::endl;
    }
    this->done();
}

void NodeSysinfoProcessor::error(const QString& eStr)
{
    if (this->retryCount == 0 && (eStr != "Host unreachable" && eStr != "Unknown error")) {
        std::cerr << "Node " << this->element->getId() << ": " << eStr.toStdString() << std::endl;
    }
    this->element->setOnline(false);
    this->runRequest();
}

void NodeSysinfoProcessor::runRequest() {
    if (this->retryCount > 0) {
        this->retryCount--;
        JsonRequest* request = new JsonRequest(QUrl("http://" + this->element->getIpAddress() + "/sysinfo-json.cgi"));
        connect(request, &JsonRequest::result, this, &NodeSysinfoProcessor::success);
        connect(request, &JsonRequest::error, this, &NodeSysinfoProcessor::error);
        connect(request, &JsonRequest::queueDelete, request, &JsonRequest::deleteLater);
        request->run();
    } else {
        this->done();
    }
}

void NodeSysinfoProcessor::done()
{
    emit finished(this);
    emit finish();
}
