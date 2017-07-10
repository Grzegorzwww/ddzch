#-------------------------------------------------
#
# Project created by QtCreator 2017-06-21T13:52:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = android_test_3
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    graphics.cpp \
    time_date_control.cpp \
    log.cpp \
    mylineedit.cpp

HEADERS  += mainwindow.h \
    defines.h \
    graphics.h \
    time_date_control.h \
    log.h \
    mylineedit.h

#/home/gwarchol/qt_workspace/android_app/android_test_3/xlsx/QtXlsxWriter-master/src/xlsx
#include(/home/gwarchol/qt_workspace/android_app/xlsx/QtXlsxWriter-master/src/xlsx/qtxlsx.pri)
include(/home/gwarchol/qt_workspace/android_app/xlsx/QtXlsxWriter-master/src/xlsx/qtxlsx.pri)

FORMS    += mainwindow.ui


CONFIG += mobility
MOBILITY = 

RESOURCES +=

DISTFILES +=

