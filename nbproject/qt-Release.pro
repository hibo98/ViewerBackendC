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
SOURCES += DataHolder.cpp JsonRequest.cpp Link.cpp Location.cpp Main2.cpp Node.cpp dataparser/DataParser.cpp dataparser/DataParserAPI.cpp main.cpp
HEADERS += DataHolder.h JsonRequest.h Link.h Location.h Main2.h Node.h dataparser/DataParser.h dataparser/DataParserAPI.h
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
