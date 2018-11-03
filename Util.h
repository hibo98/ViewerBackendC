
/* 
 * File:   Util.h
 * Author: NMerkelt
 *
 * Created on 1. November 2018, 09:59
 */

#ifndef UTIL_H
#define UTIL_H

#include <QString>

class Util {
public:
    static QString getTimeString(long millisecounds);
    static long getCurrentTimestamp();
    const static long DAYS_30 = 1000L * 60L * 60L * 24L * 30L;
private:

};

#endif /* UTIL_H */

