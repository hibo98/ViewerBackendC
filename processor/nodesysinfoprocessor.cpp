#include "nodesysinfoprocessor.h"
#include "dataparser/DataParserSysinfo.h"

#include <iostream>

NodeSysinfoProcessor::NodeSysinfoProcessor(Node* element) : QObject(nullptr)
{
    this->element = element;
    this->request = new JsonRequest(QUrl("http://" + this->element->getIpAddress() + "/sysinfo-json.cgi"));
    connect(this->request, &JsonRequest::result, this, &NodeSysinfoProcessor::success);
    connect(this->request, &JsonRequest::error, this, &NodeSysinfoProcessor::error);
}

NodeSysinfoProcessor::~NodeSysinfoProcessor()
{
    delete this->request;
}

void NodeSysinfoProcessor::run()
{
    this->runRequest();
}

void NodeSysinfoProcessor::success(QJsonDocument doc)
{
    if (doc.isObject()) {
        QJsonObject json = doc.object();
        if (json.contains("version") && json.contains("data")) {
            this->element->fill(new DataParserSysinfo(json.value("data").toObject(), json.value("verison").toInt(-1)));
        }
    } else {
        std::cerr << "Node " << this->element->getId() << ": Not well formed JSON!" << std::endl;
    }
    emit finished(this);
}

void NodeSysinfoProcessor::error(QString eStr)
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
        this->request->run();
    } else {
        emit finished(this);
    }
}
