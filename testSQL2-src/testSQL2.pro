#-------------------------------------------------
#
# Project created by QtCreator 2015-10-18T00:46:51
#
#-------------------------------------------------

QT       += core gui
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testSQL2
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    thread.cpp

HEADERS  += widget.h \
    thread.h

FORMS    += widget.ui