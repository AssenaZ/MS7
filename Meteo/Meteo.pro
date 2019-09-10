#-------------------------------------------------
#
# Project created by QtCreator 2019-09-06T15:36:38
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Meteo
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    requeteown.cpp \
    SNClientHTTP.cpp \
    meteoown.cpp

HEADERS += \
    requeteown.h \
    SNClientHTTP.h \
    meteoown.h

win32:LIBS += C:\Qt\Qt5.3.2\Tools\mingw482_32\i686-w64-mingw32\lib\libws2_32.a
