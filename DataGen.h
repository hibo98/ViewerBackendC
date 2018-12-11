#ifndef DATAGEN_H
#define DATAGEN_H

#include "DataHolder.h"
#include "MySQL.h"

#include <QObject>

class DataGen : public QObject {
    Q_OBJECT

public:
    explicit DataGen(QObject*parent = nullptr);

    static DataHolder* getDataHolder();
    static MySQL* getDatabase();

public slots:
    void start();
    void processedAPI(bool error);

private:
    static MySQL* db;
    static DataHolder* dh;
    void processNodes();
    void fillOfflineNodes();
    void collectLinks();
    void genJson();
    void saveToDatabase();
    void stop();
};

#endif /* MAIN2_H */

