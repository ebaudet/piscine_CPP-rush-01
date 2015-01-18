#-------------------------------------------------
#
# Project created by QtCreator 2015-01-17T20:50:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ft_gkrellm
TEMPLATE = app

DESTDIR = /nfs/zfs-student-2/users/2013/gpetrov/Rendu/S3/PiscineC++/RUSH/RUSH01


SOURCES += main.cpp\
        Qtwindow.cpp

HEADERS  += Qtwindow.h

LIBS     += -lncurses

FORMS    += qtwindow.ui
