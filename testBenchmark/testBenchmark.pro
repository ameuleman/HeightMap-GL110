QT       += testlib

QT       -= gui

TARGET = testBenchmark
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

include(../src/src.pri)

INCLUDEPATH = $$PWD/../src/

SOURCES += TestBenchmark.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES = $$PWD/testBenchmark.qrc
