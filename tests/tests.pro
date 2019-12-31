QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  main.cpp \
    testregexprocessor.cpp \
    ../src/regexprocessor.cpp

HEADERS += testregexprocessor.h \
    ../src/regexprocessor.h
