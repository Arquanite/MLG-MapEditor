#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T18:29:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapEditor
TEMPLATE = app

INCLUDEPATH += include/

SOURCES += src/main.cpp\
        src/mapeditor.cpp \
    src/mapviewmodel.cpp \
    src/blockviewmodel.cpp \
    src/blockdelegate.cpp \
    imageedit.cpp

HEADERS  += include/mapeditor.h \
    include/mapviewmodel.h \
    include/blockviewmodel.h \
    include/blockdelegate.h \
    imageedit.h

FORMS    += ui/mapeditor.ui \
    imageedit.ui
