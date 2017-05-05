QT += core gui opengl

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_DEPRECATED_WARNINGS

#path of the resources folder
resources_folder = $${PWD}/resources
resources_destination = $${DESTDIR}

#change slashs for backslashs in paths if using windows
win32 {
    resources_destination = $${DESTDIR}/resources

    resources_folder ~= s,/,\\,g
    resources_destination ~= s,/,\\,g
}

#Copy resources folder to the build destination
copyresources.commands = $(COPY_DIR) $${resources_folder}  $${resources_destination}
first.depends = $(first) copyresources
export(first.depends)
export(copyresources.commands)
QMAKE_EXTRA_TARGETS += first copyresources

#Files
SOURCES += $$PWD/main.cpp \
    $$PWD/controlPanel/MainWindow.cpp \
    $$PWD/rendering/DepthMap.cpp \
    $$PWD/rendering/HeightMapMesh.cpp \
    $$PWD/rendering/RenderWindow.cpp \
    $$PWD/rendering/Mesh.cpp \
    $$PWD/rendering/LvlPlan.cpp \
    $$PWD/imageProcessing/ImageProcessor.cpp

HEADERS  += $$PWD/controlPanel/MainWindow.h \
    $$PWD/rendering/RenderWindow.h \
    $$PWD/rendering/DepthMap.h \
    $$PWD/rendering/HeightMapMesh.h \
    $$PWD/rendering/Mesh.h \
    $$PWD/rendering/LvlPlan.h \
    $$PWD/imageProcessing/ImageProcessor.h \
    $$PWD/tools/ParallelTool.h \
    $$PWD/tools/Types.h

DISTFILES += $$PWD/resources/shader/displayShader.frag \
    $$PWD/resources/shader/lvlShader.frag \
    $$PWD/resources/shader/mapShader.frag \
    $$PWD/resources/shader/displayShader.vert \
    $$PWD/resources/shader/lvlShader.vert \
    $$PWD/resources/shader/mapShader.vert \
    $$PWD/resources/data/* \

FORMS    += $$PWD/controlPanel/mainwindow.ui
