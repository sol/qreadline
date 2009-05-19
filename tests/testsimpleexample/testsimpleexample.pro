TEMPLATE = app

QT += testlib
DEFINES += TESTING

CONFIG += qt warn_on debug

INCLUDEPATH += ../../examples/simple
INCLUDEPATH += ../../qreadline

HEADERS += ../../examples/simple/mainwindow.h
HEADERS += ../../qreadline/qreadline.h

SOURCES += ../../examples/simple/mainwindow.cpp
SOURCES += ../../qreadline/qreadline.cpp
SOURCES += testsimpleexample.cpp

MOC_DIR     = tmp
OBJECTS_DIR = tmp
