
/* 
 * File:   Main2.h
 * Author: NMerkelt
 *
 * Created on 13. Oktober 2018, 14:46
 */

#ifndef MAIN2_H
#define MAIN2_H

#include<qobject.h>

class Main2 : public QObject {

    Q_OBJECT

public:
    explicit Main2(QObject*parent = nullptr);

public slots:
    void stop();

signals:
    void quit();
};

#endif /* MAIN2_H */

