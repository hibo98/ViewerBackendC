
/*
 * File:   main.cpp
 * Author: NMerkelt
 *
 * Created on 13. Oktober 2018, 13:56
 */

#include <qcoreapplication.h>
#include <qobject.h>
#include <qtimer.h>
#include "Main2.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QCoreApplication app(argc, argv);

    // create and show your widgets here

    Main2 m;
    
    QObject::connect(&m, &Main2::quit, &app, &QCoreApplication::quit);
    
    QTimer::singleShot(1, &m, SLOT(stop()));
    
    return app.exec();
}
