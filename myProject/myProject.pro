#-------------------------------------------------
#
# Project created by QtCreator 2015-10-18T00:46:51
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
# QT       += xml
QT       += webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myProject
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    xmlstreamreader.cpp \
    messagepusher.cpp \
    test.cpp

HEADERS  += widget.h \
    sht11_test.h \
    xmlstreamreader.h \
    messagepusher.h \
    test.h

FORMS    += widget.ui

RESOURCES += \
    resource.qrc
