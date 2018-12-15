#include "databaseprocessor.h"

#include <QEventLoop>

DatabaseProcessor::DatabaseProcessor(QList<Node*> elements) : QObject(nullptr)
{
    this->pool.setMaxThreadCount(10);
    this->queue.append(elements);
}

DatabaseProcessor::~DatabaseProcessor()
{
}

void DatabaseProcessor::process()
{
    QEventLoop loop;
    connect(this, &DatabaseProcessor::queueEmpty, &loop, &QEventLoop::quit);
    int max = this->queue.size();
    for (int i = 0; i < 10 && i < max; i++) {
        this->processNode(this->queue.dequeue());
    }
    loop.exec();
}

void DatabaseProcessor::requestFinished(NodeDatabaseProcessor* proc)
{
    this->processing.removeAll(proc);
    if (!this->queue.isEmpty()) {
        this->processNode(this->queue.dequeue());
    } else if (this->processing.isEmpty()) {
        emit queueEmpty();
    }
}

void DatabaseProcessor::processNode(Node* node)
{
    NodeDatabaseProcessor* request = new NodeDatabaseProcessor(node);
    this->processing.append(request);
    connect(request, &NodeDatabaseProcessor::finished, this, &DatabaseProcessor::requestFinished);
    connect(request, &NodeDatabaseProcessor::done, request, &NodeDatabaseProcessor::deleteLater);
    this->pool.start(request);
}
