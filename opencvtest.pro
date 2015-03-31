#-------------------------------------------------
#
# Project created by QtCreator 2015-03-31T11:43:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencvtest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += `/usr/local/bin/pkg-config opencv --libs`

INCLUDEPATH += "/usr/local/include"
