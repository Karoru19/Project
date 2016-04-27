#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T14:53:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projekt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    osoba.cpp \
    sedzia.cpp \
    zawodnik.cpp \
    druzyna.cpp

HEADERS  += mainwindow.h \
    osoba.h \
    sedzia.h \
    zawodnik.h \
    druzyna.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
