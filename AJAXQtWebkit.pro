#-------------------------------------------------
#
# Project created by QtCreator 2014-07-01T10:19:37
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AJAXQtWebkit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    jquery-2.1.1.min.js

RESOURCES += \
    resources.qrc
