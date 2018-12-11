#include "Location.h"

#include <QJsonValue>

Location::Location(double latitude, double longitude) {
    this->latitude = latitude;
    this->longitude = longitude;
}

Location::Location(const Location& orig) : Location(orig.latitude, orig.longitude) {
}

Location::~Location() {
}

double Location::getLatitude() {
    return this->latitude;
}

double Location::getLongitude() {
    return this->longitude;
}

bool Location::isValid() {
    return true;
}

QJsonObject Location::toJson() {
    QJsonObject location;
    location.insert("latitude", QJsonValue(this->latitude));
    location.insert("longitude", QJsonValue(this->longitude));
    return location;
}

