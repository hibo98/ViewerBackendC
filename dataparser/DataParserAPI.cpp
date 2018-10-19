
/* 
 * File:   DataParserAPI.cpp
 * Author: NMerkelt
 * 
 * Created on 18. Oktober 2018, 22:58
 */

#include "DataParserAPI.h"

DataParserAPI::DataParserAPI(QJsonObject json) {
    this->json = json;
}

DataParserAPI::DataParserAPI(const DataParserAPI& orig) {
}

DataParserAPI::~DataParserAPI() {
}

QJsonObject DataParserAPI::getData() {
    
}

bool DataParserAPI::hasLinkSet() {
    return false;
}

QSet<Link*>* DataParserAPI::getLinkSet() {
    return nullptr;
}

int DataParserAPI::getClients() {
    return this->json.value("status").toObject().value("clients").toInt();
}

