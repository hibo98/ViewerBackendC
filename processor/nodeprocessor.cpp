#include "nodeprocessor.h"

#include <QEventLoop>

NodeProcessor::NodeProcessor(QList<Node*> elements) : QObject(nullptr)
{
    this->queue.append(elements);
}

NodeProcessor::~NodeProcessor()
{
}

void NodeProcessor::process()
{
    QEventLoop loop;
    connect(this, &NodeProcessor::queueEmpty, &loop, &QEventLoop::quit);
    int max = this->queue.size();
    for (int i = 0; i < 10 && i < max; i++) {
        this->processNode(this->queue.dequeue());
    }
    loop.exec();
}

void NodeProcessor::requestFinished(NodeSysinfoProcessor* proc)
{
    this->processing.removeAll(proc);
    if (!this->queue.isEmpty()) {
        this->processNode(this->queue.dequeue());
    } else if (this->processing.isEmpty()) {
        emit queueEmpty();
    }
}

void NodeProcessor::processNode(Node* node)
{
    NodeSysinfoProcessor* request = new NodeSysinfoProcessor(node);
    this->processing.append(request);
    connect(request, &NodeSysinfoProcessor::finished, this, &NodeProcessor::requestFinished);
    connect(request, &NodeSysinfoProcessor::finish, request, &NodeSysinfoProcessor::deleteLater);
    request->run();
}
