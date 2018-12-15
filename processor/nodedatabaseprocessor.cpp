#include "nodedatabaseprocessor.h"
#include "dataparser/DataParserSysinfo.h"

#include <iostream>

NodeDatabaseProcessor::NodeDatabaseProcessor(Node* element) : QObject(nullptr)
{
    this->element = element;
}

NodeDatabaseProcessor::~NodeDatabaseProcessor()
{
}

void NodeDatabaseProcessor::run()
{
    this->element->updateDatabase();
}

void NodeDatabaseProcessor::finish()
{
    emit finished(this);
    emit done();
}
