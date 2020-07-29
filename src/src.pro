QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Interface
TEMPLATE = app

CONFIG += c++11 resources_big

include (style/d1/d1.pri)
include (style/d2/d2.pri)

SOURCES += main.cpp\
        interface.cpp


HEADERS  += interface.h \
    settings.h \
    mainwindow.h

FORMS    += interface.ui
