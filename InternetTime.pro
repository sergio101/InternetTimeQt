#-------------------------------------------------
#
# Project created by QtCreator 2016-09-16T11:44:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InternetTime
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    timeconversion.cpp \
    preferences.cpp

HEADERS  += mainwindow.h \
    timeconversion.h \
    preferences.h

FORMS    += mainwindow.ui \
    preferences.ui
