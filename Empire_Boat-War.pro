#-------------------------------------------------
#
# Project created by QtCreator 2014-11-11T13:41:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Empire_Boat-War
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tablero.cpp \
    barco.cpp

HEADERS  += mainwindow.h \
    tablero.h \
    barco.h

FORMS    += mainwindow.ui \
    tablero.ui \
    barco.ui
