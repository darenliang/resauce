QT += core gui

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
    endswithfilter.cpp \
    extensionfilter.cpp \
    fileutil.cpp \
    main.cpp \
    mainwindow.cpp \
    aboutdialog.cpp \
    regexfilter.cpp \
    regexprocessor.cpp \
    resaucefileinfo.cpp \
    resaucefilemodel.cpp \
    resaucer.cpp \
    resaucerprocessor.cpp \
    startswithpredicate.cpp \
    state.cpp \
    dirutil.cpp \
    variableprocessor.cpp

HEADERS += \
    ResauceVariable.h \
    endswithfilter.h \
    extensionfilter.h \
    fileutil.h \
    info.h \
    mainwindow.h \
    aboutdialog.h \
    regexfilter.h \
    regexprocessor.h \
    resaucefileinfo.h \
    resaucefilemodel.h \
    resaucefilter.h \
    resaucer.h \
    resaucerprocessor.h \
    startswithpredicate.h \
    state.h \
    dirutil.h \
    variableprocessor.h

FORMS += \
    mainwindow.ui \
    aboutdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
