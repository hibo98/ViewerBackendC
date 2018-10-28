# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/LocalCygwin-Windows
TARGET = ViewerBackendC
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core network
SOURCES += DataGen.cpp DataHolder.cpp JsonRequest.cpp Link.cpp Location.cpp Node.cpp NodeSysinfoRequest.cpp dataparser/DataParser.cpp dataparser/DataParserAPI.cpp dataparser/DataParserSysinfo.cpp main.cpp
HEADERS += DataGen.h DataHolder.h JsonRequest.h Link.h Location.h Node.h NodeSysinfoRequest.h dataparser/DataParser.h dataparser/DataParserAPI.h dataparser/DataParserSysinfo.h
FORMS +=
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/LocalCygwin-Windows
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
equals(QT_MAJOR_VERSION, 4) {
QMAKE_CXXFLAGS += -std=c++17
}
