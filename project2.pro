#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T02:56:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project2
TEMPLATE = app


SOURCES += main.cpp\
    game.cpp \
    button.cpp \
    drum.cpp \
    score.cpp

HEADERS  += \
    game.h \
    button.h \
    drum.h \
    score.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
