
/* 
 * File:   Util.cpp
 * Author: NMerkelt
 * 
 * Created on 1. November 2018, 09:59
 */

#include "Util.h"

#include <QDateTime>

QString Util::getTimeString(long millisec) {
    QDateTime time = QDateTime::fromMSecsSinceEpoch(millisec);
    return time.toString(Qt::ISODate);
}

long Util::getCurrentTimestamp() {
    return QDateTime::currentMSecsSinceEpoch();
}

