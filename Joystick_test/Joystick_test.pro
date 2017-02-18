#-------------------------------------------------
#
# Project created by QtCreator 2017-02-17T08:40:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Joystick_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qjoystick.cpp \
    joystickview.cpp \
    myclass.cpp

HEADERS  += mainwindow.h \
    qjoystick.h \
    joystickview.h \
    myclass.h

FORMS    += mainwindow.ui \
    joystickview.ui
