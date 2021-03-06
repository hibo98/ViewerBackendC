QT += network sql
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
    Node.cpp \
    Util.cpp \
    dataparser/DataParserAPI.cpp \
    dataparser/DataParserSysinfo.cpp \
    dataparser/DataParser.cpp \
    dataparser/DataParserDB.cpp \
    processor/nodesysinfoprocessor.cpp \
    processor/nodeprocessor.cpp \
    database/nodesql.cpp \
    database/statssql.cpp \
    database/mysql.cpp

HEADERS += \
    DataGen.h \
    DataHolder.h \
    JsonFileGen.h \
    JsonRequest.h \
    Link.h \
    Location.h \
    Node.h \
    Util.h \
    dataparser/DataParser.h \
    dataparser/DataParserAPI.h \
    dataparser/DataParserSysinfo.h \
    dataparser/DataParserDB.h \
    processor/nodesysinfoprocessor.h \
    processor/nodeprocessor.h \
    database/nodesql.h \
    database/statssql.h \
    database/mysql.h
