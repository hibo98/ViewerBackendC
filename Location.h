#ifndef LOCATION_H
#define LOCATION_H

#include <QJsonObject>

class Location {
public:
    Location(double latitude, double longitude);
    Location(const Location& orig);
    virtual ~Location();
    
    double getLatitude();
    double getLongitude();
    
    bool isValid();
    QJsonObject toJson();
private:
    double latitude;
    double longitude;
};

#endif /* LOCATION_H */

