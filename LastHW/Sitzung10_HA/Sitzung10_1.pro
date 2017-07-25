QT += core
QT -= gui

CONFIG += c++11

TARGET = Sitzung10_1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    meinwidget.cpp \
    zeichenfeld.cpp

HEADERS += \
    meinwidget.h \
    zeichenfeld.h

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
