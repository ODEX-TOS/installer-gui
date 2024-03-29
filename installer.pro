QT += quick quickcontrols2
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        handler.cpp \
        main.cpp \
        model/disk.cpp \
        model/encryptedpartitions.cpp \
        model/logicvolume.cpp \
        model/network.cpp \
        model/partition.cpp \
        model/resizepartition.cpp \
        model/system.cpp \
        model/user.cpp \
        yaml.cpp

RESOURCES += qml.qrc TOS_logo.svg pictures/TOS-installer/TOS-installer-1.jpg pictures/TOS-installer/TOS-installer-2.jpg pictures/TOS-installer/TOS-installer-3.jpg pictures/TOS-installer/TOS-installer-4.jpg pictures/TOS-installer/TOS-installer-5.jpg pictures/TOS-installer/TOS-installer-6.jpg pictures/TOS-installer/TOS-installer-7.jpg pictures/TOS-installer/TOS-installer-8.jpg pictures/TOS-installer/TOS-installer-9.jpg\
            pictures/random1.jpg pictures/random2.jpg pictures/random3.jpg pictures/random4.jpg pictures/random5.jpg pictures/random6.jpg pictures/ThankYou.jpg

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    config.h \
    handler.h \
    model/disk.h \
    model/encryptedpartitions.h \
    model/logicvolume.h \
    model/network.h \
    model/partition.h \
    model/resizepartition.h \
    model/system.h \
    model/user.h \
    yaml.h

DISTFILES += \
    config/config.yaml \
    config/packages.txt \
    config/rootinstall.sh \
    config/standard.yaml \
    config/userinstall.sh \
    config/wayland.txt \
    config/yay.txt \
    config/yayinstall.sh \
    pictures/slide2.png
