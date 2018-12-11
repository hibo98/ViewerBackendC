#include "Util.h"

#include <QDateTime>

const long long Util::DAYS_30 = 1000LL * 60LL * 60LL * 24LL * 30LL;

QString Util::getTimeString(long long millisec) {
    QDateTime time = QDateTime::fromMSecsSinceEpoch(millisec);
    return time.toString(Qt::ISODate);
}

long long Util::getCurrentTimestamp() {
    return QDateTime::currentMSecsSinceEpoch();
}

