#ifndef UTIL_H
#define UTIL_H

#include <QString>

class Util {
public:
    static QString getTimeString(long long millisecounds);
    static long long getCurrentTimestamp();
    const static long long DAYS_30;
private:

};

#endif /* UTIL_H */

