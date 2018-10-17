
/* 
 * File:   Location.cpp
 * Author: NMerkelt
 * 
 * Created on 17. Oktober 2018, 13:09
 */

#include "Location.h"

Location::Location(float latitude, float longitude) {
    this->latitude = latitude;
    this->longitude = longitude;
}

Location::Location(const Location& orig) : Location(orig.latitude, orig.longitude) {
}

Location::~Location() {
}

float Location::getLatitude() {
    return this->latitude;
}

float Location::getLongitude() {
    return this->longitude;
}

bool Location::isValid() {
    return true;
}

