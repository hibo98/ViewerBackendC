
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
private:

};

#endif /* UTIL_H */

