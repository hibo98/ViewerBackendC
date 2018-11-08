
/* 
 * File:   NodeProcessor.cpp
 * Author: NMerkelt
 * 
 * Created on 6. November 2018, 11:14
 */

#include "NodeProcessor.h"
#include "NodeSysinfoRequest.h"

#include <QEventLoop>

NodeProcessor::NodeProcessor(QList<Node*> nodes) : QObject(nullptr) {
    this->queue.append(nodes);
}

NodeProcessor::~NodeProcessor() {
}

void NodeProcessor::process() {
    QEventLoop loop;
    connect(this, &NodeProcessor::queueEmpty, &loop, &QEventLoop::quit);
    int max = this->queue.size();
    for (int i = 0; i < 10 && i < max; i++) {
        this->processNode(this->queue.dequeue());
    }
    loop.exec();
}

void NodeProcessor::requestFinished(NodeSysinfoRequest* n) {
    this->processing.removeAll(n);
    delete n;
    if (!this->queue.isEmpty()) {
        this->processNode(this->queue.dequeue());
    } else if (this->processing.isEmpty()) {
        emit queueEmpty();
    }
}

void NodeProcessor::processNode(Node* n) {
    NodeSysinfoRequest* request = new NodeSysinfoRequest(n);
    this->processing.append(request);
    connect(request, &NodeSysinfoRequest::finished, this, &NodeProcessor::requestFinished);
    request->run();
}