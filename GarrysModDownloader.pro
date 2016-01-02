#-------------------------------------------------
#
# Project created by QtCreator 2015-12-30T23:06:03
#
#-------------------------------------------------

QT       += core gui
QT+=network
DEFINES  += QT_NO_SSL
CONFIG += static

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += C:/Qt/zlib-1.2.8
LIBS += -LC:/Qt/zlib-1.2.8 -lz
INCLUDEPATH += C:/Qt/quazip-0.7/quazip
LIBS += -LC:/Qt/quazip-0.7/quazip/release -lquazip

TARGET = GarrysModDownloader
TEMPLATE = app

SOURCES += main.cpp \
            mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
