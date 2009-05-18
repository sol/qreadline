TEMPLATE = app

CONFIG += qt warn_on debug link_prl

LIBS += -L../../qreadline -lqreadline

INCLUDEPATH += ../../qreadline

HEADERS += mainwindow.h
SOURCES += main.cpp
SOURCES += mainwindow.cpp

MOC_DIR     = tmp
OBJECTS_DIR = tmp
