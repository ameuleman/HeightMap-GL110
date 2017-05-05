QT       += testlib

QT       -= gui

TARGET = tests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

include($$PWD/../src/src.pri)

HEADERS += $$PWD/TestImageProcessor.h \
    $$PWD/TestHeightMapMesh.h \
    $$PWD/TestLvlPlanMesh.h \

SOURCES += $$PWD/main.cpp\
    $$PWD/TestImageProcessor.cpp \
    $$PWD/TestHeightMapMesh.cpp \
    $$PWD/TestLvlPlanMesh.cpp \

DEFINES += SRCDIR=\\\"$$PWD/\\\"
