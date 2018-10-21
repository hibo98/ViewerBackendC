
/*
 * File:   main.cpp
 * Author: NMerkelt
 *
 * Created on 13. Oktober 2018, 13:56
 */

#include <qcoreapplication.h>
#include <qobject.h>
#include <qtimer.h>
#include "DataGen.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QCoreApplication app(argc, argv);

    // create and show your widgets here

    DataGen m;
    
    QObject::connect(&m, &DataGen::quit, &app, &QCoreApplication::quit);
    
    QTimer::singleShot(1, &m, SLOT(stop()));
    
    return app.exec();
}
