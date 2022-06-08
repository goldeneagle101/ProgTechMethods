QT += testlib sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_qt.cpp \
    P:/project_QT/abc/latest_version/Server_Functions.cpp


HEADERS += \
    P:/project_QT/abc/latest_version/Server_Functions.h \
    P:/project_QT/abc/latest_version/database.h
