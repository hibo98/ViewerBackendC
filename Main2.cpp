
/* 
 * File:   Main2.cpp
 * Author: NMerkelt
 * 
 * Created on 13. Oktober 2018, 14:46
 */

#include "Main2.h"

Main2::Main2(QObject*parent) : QObject(parent) {
}

void Main2::stop() {
    emit quit();
}



