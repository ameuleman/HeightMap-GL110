QT += core gui opengl

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = build/
TARGET = heightMap
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

RESOURCES     = src.qrc

#Files
SOURCES += main.cpp \
    controlPanel/MainWindow.cpp \
    rendering/DepthMap.cpp \
    rendering/HeightMapMesh.cpp \
    rendering/RenderWindow.cpp \
    rendering/Mesh.cpp \
    rendering/LvlPlan.cpp \
    imageProcessing/ImageProcessor.cpp

HEADERS  += controlPanel/MainWindow.h \
    rendering/RenderWindow.h \
    rendering/DepthMap.h \
    rendering/HeightMapMesh.h \
    rendering/Mesh.h \
    rendering/LvlPlan.h \
    imageProcessing/ImageProcessor.h \
    tools/ParallelTool.h \
    tools/Types.h

FORMS    += controlPanel/mainwindow.ui
