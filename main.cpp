#include "DataGen.h"

#include <QCoreApplication>
#include <QTimer>

int main(int argc, char *argv[]) {

    QCoreApplication app(argc, argv);

    DataGen m;

    QTimer::singleShot(1, &m, SLOT(start()));

    return app.exec();
}
