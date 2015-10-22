#-------------------------------------------------
#
# Project created by QtCreator 2015-10-10T15:34:55
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

QT       += network

TARGET = tst_teststest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    server_tests/servertests.cpp \
    server_tests/main.cpp \
    common_tests/loggertests.cpp \
    common_tests/datetimetests.cpp \
    client_tests/client_tests_test.cpp \
    common_tests/commontests.cpp \
    server_tests/taskfactorytests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../client/client_lib/release/ -lclient_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../client/client_lib/debug/ -lclient_lib
else:unix: LIBS += -L$$OUT_PWD/../client/client_lib/ -lclient_lib

INCLUDEPATH += $$PWD/../client/client_lib
DEPENDPATH += $$PWD/../client/client_lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../client/client_lib/release/libclient_lib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../client/client_lib/debug/libclient_lib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../client/client_lib/release/client_lib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../client/client_lib/debug/client_lib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../client/client_lib/libclient_lib.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../server/server_lib/release/ -lserver_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../server/server_lib/debug/ -lserver_lib
else:unix: LIBS += -L$$OUT_PWD/../server/server_lib/ -lserver_lib

INCLUDEPATH += $$PWD/../server/server_lib
DEPENDPATH += $$PWD/../server/server_lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../server/server_lib/release/libserver_lib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../server/server_lib/debug/libserver_lib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../server/server_lib/release/server_lib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../server/server_lib/debug/server_lib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../server/server_lib/libserver_lib.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix: LIBS += -L$$OUT_PWD/../common/ -lcommon

INCLUDEPATH += $$PWD/../common
DEPENDPATH += $$PWD/../common

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/release/libcommon.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/debug/libcommon.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/release/common.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/debug/common.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../common/libcommon.a

HEADERS += \
    autotest.h
