#-------------------------------------------------
#
# Project created by QtCreator 2015-08-24T20:52:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtHomeBtn
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    picbutton.cpp \
    btnanimation.cpp

HEADERS  += widget.h \
    picbutton.h \
    btnanimation.h \
    comdef.h

FORMS    += widget.ui

RESOURCES += \
    rc.qrc
