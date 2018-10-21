#############################################################################
# Makefile for building: dist/Debug/LocalCygwin-Windows/ViewerBackendC.exe
# Generated by qmake (3.1) (Qt 5.9.4)
# Project:  nbproject/qt-Debug.pro
# Template: app
# Command: /cygdrive/C/cygwin64/bin/qmake-qt5 -o qttmp-Debug.mk nbproject/qt-Debug.pro VPATH=. -spec cygwin-g++
#############################################################################

MAKEFILE      = qttmp-Debug.mk

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NETWORK_LIB -DQT_CORE_LIB
CFLAGS        = -fno-keep-inline-dllexport -D_GNU_SOURCE -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -fno-keep-inline-dllexport -D_GNU_SOURCE -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -Inbproject -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtNetwork -isystem /usr/include/qt5/QtCore -I. -I/usr/lib/qt5/mkspecs/cygwin-g++
QMAKE         = /cygdrive/C/cygwin64/bin/qmake-qt5
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /cygdrive/C/cygwin64/bin/qmake-qt5 -install qinstall
QINSTALL_PROGRAM = /cygdrive/C/cygwin64/bin/qmake-qt5 -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = ViewerBackendC1.0.0
DISTDIR = /cygdrive/d/NetBeansProjekte/ViewerBackendC/build/Debug/LocalCygwin-Windows/ViewerBackendC1.0.0
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS) -lQt5Network -lQt5Core -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = 

####### Output directory

OBJECTS_DIR   = build/Debug/LocalCygwin-Windows/

####### Files

SOURCES       = DataGen.cpp \
		DataHolder.cpp \
		JsonRequest.cpp \
		Link.cpp \
		Location.cpp \
		Node.cpp \
		dataparser/DataParser.cpp \
		dataparser/DataParserAPI.cpp \
		dataparser/DataParserSysinfo.cpp \
		main.cpp moc_DataGen.cpp \
		moc_DataHolder.cpp \
		moc_JsonRequest.cpp
OBJECTS       = build/Debug/LocalCygwin-Windows/DataGen.o \
		build/Debug/LocalCygwin-Windows/DataHolder.o \
		build/Debug/LocalCygwin-Windows/JsonRequest.o \
		build/Debug/LocalCygwin-Windows/Link.o \
		build/Debug/LocalCygwin-Windows/Location.o \
		build/Debug/LocalCygwin-Windows/Node.o \
		build/Debug/LocalCygwin-Windows/DataParser.o \
		build/Debug/LocalCygwin-Windows/DataParserAPI.o \
		build/Debug/LocalCygwin-Windows/DataParserSysinfo.o \
		build/Debug/LocalCygwin-Windows/main.o \
		build/Debug/LocalCygwin-Windows/moc_DataGen.o \
		build/Debug/LocalCygwin-Windows/moc_DataHolder.o \
		build/Debug/LocalCygwin-Windows/moc_JsonRequest.o
DIST          = /usr/lib/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/qt5/mkspecs/common/unix.conf \
		/usr/lib/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/qt5/mkspecs/qconfig.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_help.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_help_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_networkauth.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_networkauth_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_remoteobjects.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_remoteobjects_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_repparser.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_repparser_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_webchannel.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_webchannel_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/qt5/mkspecs/cygwin-g++/qmake.conf \
		/usr/lib/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/qt5/mkspecs/features/default_post.prf \
		/usr/lib/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/qt5/mkspecs/features/qt.prf \
		/usr/lib/qt5/mkspecs/features/resources.prf \
		/usr/lib/qt5/mkspecs/features/moc.prf \
		/usr/lib/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/qt5/mkspecs/features/yacc.prf \
		/usr/lib/qt5/mkspecs/features/lex.prf \
		nbproject/nbproject/qt-Debug.pro DataGen.h \
		DataHolder.h \
		JsonRequest.h \
		Link.h \
		Location.h \
		Node.h \
		dataparser/DataParser.h \
		dataparser/DataParserAPI.h \
		dataparser/DataParserSysinfo.h DataGen.cpp \
		DataHolder.cpp \
		JsonRequest.cpp \
		Link.cpp \
		Location.cpp \
		Node.cpp \
		dataparser/DataParser.cpp \
		dataparser/DataParserAPI.cpp \
		dataparser/DataParserSysinfo.cpp \
		main.cpp
QMAKE_TARGET  = ViewerBackendC
DESTDIR       = dist/Debug/LocalCygwin-Windows/
TARGET        = dist/Debug/LocalCygwin-Windows/ViewerBackendC.exe


first: all
####### Build rules

$(TARGET):  $(OBJECTS)  
	@test -d dist/Debug/LocalCygwin-Windows/ || mkdir -p dist/Debug/LocalCygwin-Windows/
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

qttmp-Debug.mk: nbproject/qt-Debug.pro /usr/lib/qt5/mkspecs/cygwin-g++/qmake.conf /usr/lib/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/qt5/mkspecs/common/unix.conf \
		/usr/lib/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/qt5/mkspecs/qconfig.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_help.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_help_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_networkauth.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_networkauth_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_remoteobjects.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_remoteobjects_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_repparser.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_repparser_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_webchannel.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_webchannel_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/qt5/mkspecs/cygwin-g++/qmake.conf \
		/usr/lib/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/qt5/mkspecs/features/default_post.prf \
		/usr/lib/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/qt5/mkspecs/features/qt.prf \
		/usr/lib/qt5/mkspecs/features/resources.prf \
		/usr/lib/qt5/mkspecs/features/moc.prf \
		/usr/lib/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/qt5/mkspecs/features/yacc.prf \
		/usr/lib/qt5/mkspecs/features/lex.prf \
		nbproject/qt-Debug.pro
	$(QMAKE) -o qttmp-Debug.mk nbproject/qt-Debug.pro VPATH=. -spec cygwin-g++
/usr/lib/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/qt5/mkspecs/common/unix.conf:
/usr/lib/qt5/mkspecs/common/sanitize.conf:
/usr/lib/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/qt5/mkspecs/common/g++-base.conf:
/usr/lib/qt5/mkspecs/qconfig.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_help.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_help_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_networkauth.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_networkauth_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qml_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_qmltest_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_quick_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_quickwidgets.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_remoteobjects.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_remoteobjects_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_repparser.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_repparser_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_webchannel.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_webchannel_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/qt5/mkspecs/features/qt_config.prf:
/usr/lib/qt5/mkspecs/cygwin-g++/qmake.conf:
/usr/lib/qt5/mkspecs/features/spec_post.prf:
/usr/lib/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/qt5/mkspecs/features/toolchain.prf:
/usr/lib/qt5/mkspecs/features/default_pre.prf:
/usr/lib/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/qt5/mkspecs/features/default_post.prf:
/usr/lib/qt5/mkspecs/features/warn_on.prf:
/usr/lib/qt5/mkspecs/features/qt.prf:
/usr/lib/qt5/mkspecs/features/resources.prf:
/usr/lib/qt5/mkspecs/features/moc.prf:
/usr/lib/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/qt5/mkspecs/features/file_copies.prf:
/usr/lib/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/qt5/mkspecs/features/exceptions.prf:
/usr/lib/qt5/mkspecs/features/yacc.prf:
/usr/lib/qt5/mkspecs/features/lex.prf:
nbproject/qt-Debug.pro:
qmake: FORCE
	@$(QMAKE) -o qttmp-Debug.mk nbproject/qt-Debug.pro VPATH=. -spec cygwin-g++

qmake_all: FORCE


all: qttmp-Debug.mk $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents DataGen.h DataHolder.h JsonRequest.h Link.h Location.h Node.h dataparser/DataParser.h dataparser/DataParserAPI.h dataparser/DataParserSysinfo.h $(DISTDIR)/
	$(COPY_FILE) --parents DataGen.cpp DataHolder.cpp JsonRequest.cpp Link.cpp Location.cpp Node.cpp dataparser/DataParser.cpp dataparser/DataParserAPI.cpp dataparser/DataParserSysinfo.cpp main.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) qttmp-Debug.mk


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib/qt5/mkspecs/features/data/dummy.cpp
	g++ -fno-keep-inline-dllexport -D_GNU_SOURCE -pipe -g -Wall -W -dM -E -o moc_predefs.h /usr/lib/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_DataGen.cpp moc_DataHolder.cpp moc_JsonRequest.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_DataGen.cpp moc_DataHolder.cpp moc_JsonRequest.cpp
moc_DataGen.cpp: DataHolder.h \
		Node.h \
		Link.h \
		Location.h \
		dataparser/DataParser.h \
		DataGen.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt5/mkspecs/cygwin-g++ -I/cygdrive/d/NetBeansProjekte/ViewerBackendC/nbproject -I/usr/include/qt5 -I/usr/include/qt5/QtNetwork -I/usr/include/qt5/QtCore -I. -I/usr/lib/gcc/x86_64-pc-cygwin/7.3.0/include/c++ -I/usr/lib/gcc/x86_64-pc-cygwin/7.3.0/include/c++/x86_64-pc-cygwin -I/usr/lib/gcc/x86_64-pc-cygwin/7.3.0/include/c++/backward -I/usr/lib/gcc/x86_64-pc-cygwin/7.3.0/include -I/usr/include -I/usr/include/w32api DataGen.h -o moc_DataGen.cpp

moc_DataHolder.cpp: Node.h \
		Link.h \
		Location.h \
		dataparser/DataParser.h \
		DataHolder.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt5/mkspecs/cygwin-g++ -I/cygdrive/d/NetBeansProjekte/ViewerBackendC/nbproject -I/usr/include/qt5 -I/usr/include/qt5/QtNetwork -I/usr/include/qt5/QtCore -I. -I/usr/lib/gcc/x86_64-pc-cygwin/7.3.0/include/c++ -I/usr/lib/gcc/x86_64-pc-cygwin/7.3.0/include/c++/x86_64-pc-cygwin -I/usr/lib/gcc/x86_64-pc-cygwin/7.3.0/include/c++/backward -I/usr/lib/gcc/x86_64-pc-cygwin/7.3.0/include -I/usr/include -I/usr/include/w32api DataHolder.h -o moc_DataHolder.cpp

moc_JsonRequest.cpp: JsonRequest.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/qt5/mkspecs/cygwin-g++ -I/cygdrive/d/NetBeansProjekte/ViewerBackendC/nbproject -I/usr/include/qt5 -I/usr/include/qt5/QtNetwork -I/usr/include/qt5/QtCore -I. -I/usr/lib/gcc/x86_64-pc-cygwin/7.3.0/include/c++ -I/usr/lib/gcc/x86_64-pc-cygwin/7.3.0/include/c++/x86_64-pc-cygwin -I/usr/lib/gcc/x86_64-pc-cygwin/7.3.0/include/c++/backward -I/usr/lib/gcc/x86_64-pc-cygwin/7.3.0/include -I/usr/include -I/usr/include/w32api JsonRequest.h -o moc_JsonRequest.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_predefs_clean compiler_moc_header_clean 

####### Compile

build/Debug/LocalCygwin-Windows/DataGen.o: DataGen.cpp DataGen.h \
		DataHolder.h \
		Node.h \
		Link.h \
		Location.h \
		dataparser/DataParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/DataGen.o DataGen.cpp

build/Debug/LocalCygwin-Windows/DataHolder.o: DataHolder.cpp DataHolder.h \
		Node.h \
		Link.h \
		Location.h \
		dataparser/DataParser.h \
		JsonRequest.h \
		dataparser/DataParserAPI.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/DataHolder.o DataHolder.cpp

build/Debug/LocalCygwin-Windows/JsonRequest.o: JsonRequest.cpp JsonRequest.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/JsonRequest.o JsonRequest.cpp

build/Debug/LocalCygwin-Windows/Link.o: Link.cpp Link.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/Link.o Link.cpp

build/Debug/LocalCygwin-Windows/Location.o: Location.cpp Location.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/Location.o Location.cpp

build/Debug/LocalCygwin-Windows/Node.o: Node.cpp Node.h \
		Link.h \
		Location.h \
		dataparser/DataParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/Node.o Node.cpp

build/Debug/LocalCygwin-Windows/DataParser.o: dataparser/DataParser.cpp dataparser/DataParser.h \
		Link.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/DataParser.o dataparser/DataParser.cpp

build/Debug/LocalCygwin-Windows/DataParserAPI.o: dataparser/DataParserAPI.cpp dataparser/DataParserAPI.h \
		dataparser/DataParser.h \
		Link.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/DataParserAPI.o dataparser/DataParserAPI.cpp

build/Debug/LocalCygwin-Windows/DataParserSysinfo.o: dataparser/DataParserSysinfo.cpp DataGen.h \
		DataHolder.h \
		Node.h \
		Link.h \
		Location.h \
		dataparser/DataParser.h \
		dataparser/DataParserSysinfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/DataParserSysinfo.o dataparser/DataParserSysinfo.cpp

build/Debug/LocalCygwin-Windows/main.o: main.cpp DataGen.h \
		DataHolder.h \
		Node.h \
		Link.h \
		Location.h \
		dataparser/DataParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/main.o main.cpp

build/Debug/LocalCygwin-Windows/moc_DataGen.o: moc_DataGen.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/moc_DataGen.o moc_DataGen.cpp

build/Debug/LocalCygwin-Windows/moc_DataHolder.o: moc_DataHolder.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/moc_DataHolder.o moc_DataHolder.cpp

build/Debug/LocalCygwin-Windows/moc_JsonRequest.o: moc_JsonRequest.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/LocalCygwin-Windows/moc_JsonRequest.o moc_JsonRequest.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

