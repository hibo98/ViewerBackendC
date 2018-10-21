
/* 
 * File:   Main2.cpp
 * Author: NMerkelt
 * 
 * Created on 13. Oktober 2018, 14:46
 */

#include "DataGen.h"

DataHolder* DataGen::dh = nullptr;

DataGen::DataGen(QObject*parent) : QObject(parent) {
    DataGen::dh = new DataHolder();
}

void DataGen::stop() {
    DataGen::dh->requestAPI();
    //emit quit();
}

DataHolder* DataGen::getDataHolder() {
    return DataGen::dh;
}

