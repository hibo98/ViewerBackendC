
/* 
 * File:   Location.h
 * Author: NMerkelt
 *
 * Created on 17. Oktober 2018, 13:09
 */

#ifndef LOCATION_H
#define LOCATION_H

#include <QJsonObject>

class Location {
public:
    Location(float latitude, float longitude);
    Location(const Location& orig);
    virtual ~Location();
    
    float getLatitude();
    float getLongitude();
    
    bool isValid();
    QJsonObject toJson();
private:
    float latitude;
    float longitude;
};

#endif /* LOCATION_H */

