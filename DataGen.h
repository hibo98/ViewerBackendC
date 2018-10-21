
/* 
 * File:   Main2.h
 * Author: NMerkelt
 *
 * Created on 13. Oktober 2018, 14:46
 */

#ifndef DATAGEN_H
#define DATAGEN_H

#include "DataHolder.h"

#include <QObject>

class DataGen : public QObject {
    Q_OBJECT

public:
    explicit DataGen(QObject*parent = nullptr);

    static DataHolder* getDataHolder();

public slots:
    void stop();

signals:
    void quit();

private:
    static DataHolder* dh;
};

#endif /* MAIN2_H */
