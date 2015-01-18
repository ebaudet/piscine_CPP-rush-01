#-------------------------------------------------
#
# Project created by QtCreator 2015-01-17T20:50:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ft_gkrellm
TEMPLATE = app


SOURCES += main.cpp\
        Qtwindow.cpp \
    MonitorNcurses.cpp \
    IMonitorDisplay.cpp \
    MonitorQt.cpp

HEADERS  += Qtwindow.h \
    IMonitorDisplay.hpp \
    MonitorNcurses.hpp \
    MonitorQt.hpp

LIBS     += -lncurses

FORMS    += qtwindow.ui
