QT       += core gui
QT       +=sql
QT       += multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cbejeweleddlg.cpp \
    cconfig.cpp \
    cconfiglogic.cpp \
    cgamedlg.cpp \
    cgamelogic.cpp \
    chelpdlg.cpp \
    choose.cpp \
    cjewel.cpp \
    cmenudlg.cpp \
    crankdao.cpp \
    crankdlg.cpp \
    csetdlg.cpp \
    main.cpp \
    mainwindow.cpp \
    picture.cpp \
    qnamedlg.cpp \
    qsetupdlg.cpp \
    capptool.cpp \
    cconfigdao.cpp \
    cmusicplayer.cpp \
    cranklogic.cpp

HEADERS += \
    cbejeweleddlg.h \
    cconfig.h \
    cconfiglogic.h \
    cgamedlg.h \
    cgamelogic.h \
    chelpdlg.h \
    choose.h \
    cjewel.h \
    cmenudlg.h \
    connectiondb.h \
    crankdao.h \
    crankdlg.h \
    csetdlg.h \
    global.h \
    mainwindow.h \
    picture.h \
    qnamedlg.h \
    qsetupdlg.h \
    capptool.h \
    cconfigdao.h \
    cmusicplayer.h \
    cranklogic.h

FORMS += \
    cbejeweleddlg.ui \
    cgamedlg.ui \
    chelpdlg.ui \
    crankdlg.ui \
    csetdlg.ui \
    mainwindow.ui \
    qnamedlg.ui \
    qsetupdlg.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
