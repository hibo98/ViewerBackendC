QT += network
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DataGen.cpp \
    DataHolder.cpp \
    JsonFileGen.cpp \
    JsonRequest.cpp \
    Link.cpp \
    Location.cpp \
    main.cpp \
    MySQL.cpp \
    Node.cpp \
    Util.cpp \
    dataparser/DataParserAPI.cpp \
    dataparser/DataParserSysinfo.cpp \
    dataparser/DataParser.cpp \
    dataparser/DataParserDB.cpp \
    StatsSQL.cpp \
    processor/nodesysinfoprocessor.cpp \
    processor/nodeprocessor.cpp \
    processor/databaseprocessor.cpp \
    processor/nodedatabaseprocessor.cpp

HEADERS += \
    DataGen.h \
    DataHolder.h \
    JsonFileGen.h \
    JsonRequest.h \
    Link.h \
    Location.h \
    MySQL.h \
    Node.h \
    Util.h \
    dataparser/DataParser.h \
    dataparser/DataParserAPI.h \
    dataparser/DataParserSysinfo.h \
    dataparser/DataParserDB.h \
    StatsSQL.h \
    processor/nodesysinfoprocessor.h \
    processor/nodeprocessor.h \
    processor/databaseprocessor.h \
    processor/nodedatabaseprocessor.h


unix:!macx: LIBS += -L$$PWD/../../../../home/nmerkelt/Downloads/mysql-connector-c++-8.0.13-linux-glibc2.12-x86-64bit/lib64/ -lmysqlcppconn

INCLUDEPATH += $$PWD/../../../../home/nmerkelt/Downloads/mysql-connector-c++-8.0.13-linux-glibc2.12-x86-64bit/include
DEPENDPATH += $$PWD/../../../../home/nmerkelt/Downloads/mysql-connector-c++-8.0.13-linux-glibc2.12-x86-64bit/include
