#-------------------------------------------------
#
# Project created by QtCreator 2019-09-05T12:24:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = installer-gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        diskoptions.cpp \
        main.cpp \
        mainwindow.cpp \
        model/disk.cpp \
        model/encryptedpartitions.cpp \
        model/logicvolme.cpp \
        model/partition.cpp \
        model/resizepartition.cpp

HEADERS += \
        diskoptions.h \
        mainwindow.h \
        model/disk.h \
        model/encryptedpartitions.h \
        model/logicvolume.h \
        model/partition.h \
        model/resizepartition.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config/config.yaml \
    config/packages.txt \
    config/rootinstall.sh \
    config/standard.yaml \
    config/userinstall.sh \
    config/wayland.txt \
    config/yay.txt \
    config/yayinstall.sh
