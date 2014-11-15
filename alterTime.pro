#-------------------------------------------------
#
# Project created by QtCreator 2014-11-10T14:46:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alterTime
TEMPLATE = app
PRECOMPILED_HEADER = stable.h

SOURCES += main.cpp\
        widget.cpp \
    delaythread.cpp

HEADERS  += widget.h \
    delaythread.h

FORMS    += widget.ui

RESOURCES += \
    res.qrc

OTHER_FILES += \
    icon.rc
RC_FILE = icon.rc
