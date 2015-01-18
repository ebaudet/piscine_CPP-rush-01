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
    MonitorQt.cpp \
    IMonitorModule.cpp \
    Module.cpp \
    HostModule.cpp

HEADERS  += Qtwindow.h \
    IMonitorDisplay.hpp \
    MonitorNcurses.hpp \
    MonitorQt.hpp \
    IMonitorModule.hpp \
    Module.hpp \
    HostModule.hpp

LIBS     += -lncurses

FORMS    += qtwindow.ui
