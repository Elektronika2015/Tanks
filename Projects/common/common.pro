#-------------------------------------------------
#
# Project created by QtCreator 2015-10-10T15:39:17
#
#-------------------------------------------------

QT       -= gui
QT       += network

DEFINES += COMMON_LIB

TARGET = common
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    bullet.cpp \
    logger.cpp \
    datetime.cpp

HEADERS += \
    common_lib.h \
    bullet.h \
    logger.h \
    datetime.h \
    common_codes.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
