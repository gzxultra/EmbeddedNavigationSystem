#-------------------------------------------------
#
# Project created by QtCreator 2015-10-18T00:46:51
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myProject
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    sht11_test.h

FORMS    += widget.ui

RESOURCES += \
    source.qrc