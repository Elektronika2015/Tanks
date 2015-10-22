#-------------------------------------------------
#
# Project created by QtCreator 2015-10-10T13:14:01
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../client_lib/release/ -lclient_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../client_lib/debug/ -lclient_lib
else:unix: LIBS += -L$$OUT_PWD/../client_lib/ -lclient_lib

INCLUDEPATH += $$PWD/../client_lib
DEPENDPATH += $$PWD/../client_lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../client_lib/release/libclient_lib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../client_lib/debug/libclient_lib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../client_lib/release/client_lib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../client_lib/debug/client_lib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../client_lib/libclient_lib.a
