#-------------------------------------------------
#
# Project created by QtCreator 2014-02-03T15:37:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = autocomplete_roman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    romancomp_lineedit.cpp

HEADERS  += mainwindow.h \
    romancomp_lineedit.h

FORMS    += mainwindow.ui
CONFIG   += C++11
