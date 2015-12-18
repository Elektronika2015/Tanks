#-------------------------------------------------
#
# Project created by QtCreator 2015-10-10T13:16:45
#
#-------------------------------------------------

QT       -= gui
QT += network

DEFINES += SERVER_LIB

TARGET = server_lib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    thread.cpp \
    tcpserver.cpp \
    player_client.cpp \
    positionchangedtask.cpp \
    taskfactory.cpp \
    bullet.cpp

HEADERS += server_lib.h \
    thread.h \
    tcpserver.h \
    player_client.h \
    positionchangedtask.h \
    taskfactory.h \
    bullet.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../common/debug/ -lcommon
else:unix: LIBS += -L$$OUT_PWD/../../common/ -lcommon

INCLUDEPATH += $$PWD/../../common
DEPENDPATH += $$PWD/../../common

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../common/release/libcommon.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../common/debug/libcommon.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../common/release/common.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../common/debug/common.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../common/libcommon.a
