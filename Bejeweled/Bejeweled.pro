#-------------------------------------------------
#
# Project created by QtCreator 2020-05-15T14:59:30
#
#-------------------------------------------------

QT       += core gui
QT       +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bejeweled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    cbejeweleddlg.cpp \
    cgamedlg.cpp \
    chelpdlg.cpp \
    choose.cpp \
    cjewel.cpp \
    cmenudlg.cpp \
    crankdlg.cpp \
    csetdlg.cpp \
        main.cpp \
        mainwindow.cpp \
    cranklogic.cpp \
    cconfig.cpp \
    cconfiglogic.cpp \
    cgamelogic.cpp \
    crankdao.cpp \
    cbejeweleddlg.cpp \
    cgamedlg.cpp \
    choose.cpp \
    cjewel.cpp \
    picture.cpp \
    qnamedlg.cpp \
    qsetupdlg.cpp

HEADERS += \
    cbejeweleddlg.h \
    cgamedlg.h \
    chelpdlg.h \
    choose.h \
    cjewel.h \
    cmenudlg.h \
    crankdlg.h \
    csetdlg.h \
        mainwindow.h \
    cranklogic.h \
    connectiondb.h \
    cconfig.h \
    cconfiglogic.h \
    cgamelogic.h \
    global.h \
    crankdao.h \
    cbejeweleddlg.h \
    cgamedlg.h \
    choose.h \
    cjewel.h \
    picture.h \
    qnamedlg.h \
    qsetupdlg.h

FORMS += \
        cbejeweleddlg.ui \
        cgamedlg.ui \
        chelpdlg.ui \
        crankdlg.ui \
        csetdlg.ui \
        csetdlg.ui \
        mainwindow.ui \
        qnamedlg.ui \
    qsetupdlg.ui
