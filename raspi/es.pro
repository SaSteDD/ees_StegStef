#-------------------------------------------------
#
# Project created by QtCreator 2013-05-19T18:06:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = es
TEMPLATE = app

QMAKE_CXXFLAGS += -std=gnu++0x #we need this for extended initializer lists


SOURCES += main.cpp\
        mainwindow.cpp \
    btwahldialog.cpp \
    stepdialog.cpp \
    taskdialog.cpp \
    taskdialogtablewidget.cpp \
    bluetoothdiscovery.cpp \
    loggerwidget.cpp \
    nxtcommunicator.cpp \
    btCom.c \
    trackview.cpp \
    taskstatewidget.cpp

HEADERS  += mainwindow.h \
    btwahldialog.h \
    stepdialog.h \
    taskdialog.h \
    taskdialogtablewidget.h \
    types.h \
    bluetoothdiscovery.h \
    loggerwidget.h \
    nxtcommunicator.h \
    btCom.h \
    trackview.h \
    taskstatewidget.h

FORMS    += mainwindow.ui\
	    btwahl.ui\
	    stepdialog.ui\
	    taskdialog.ui

RESOURCES += \
    ressources.qrc


unix:!macx: LIBS += -lbluetooth
