QT += core
QT -= gui

CONFIG += c++11

TARGET = CPPong
CONFIG -= console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    meinwidget.cpp \
    canvas.cpp \
    form.cpp \
    global.cpp \
    globalforms.cpp

HEADERS += \
    meinwidget.h \
    canvas.h \
    form.h \
    global.h \
    globalforms.h

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
