#-------------------------------------------------
#
# Project created by QtCreator 2014-12-02T10:37:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = arkanoid
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    ImageManager.cpp \
    field.cpp \
    drawer.cpp

HEADERS  += widget.h \
    ImageManager.h \
    field.h \
    drawer.h

FORMS    += widget.ui

RESOURCES += \
    resources.qrc

QMAKE_CXXFLAGS += -std=c++11 -Werror
