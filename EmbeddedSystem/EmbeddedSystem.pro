#-------------------------------------------------
#
# Project created by QtCreator 2015-11-14T10:45:03
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
# QT       += xml
QT += webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EmbeddedSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    httpmanager.cpp \
    xmlparser.cpp

HEADERS  += mainwindow.h \
    httpmanager.h \
    xmlparser.h

FORMS    += mainwindow.ui
