TEMPLATE = app

CONFIG += qt warn_on debug

INCLUDEPATH += ../../qreadline


# uncomment the following two lines..
# CONFIG += link_prl
# LIBS += -L../../qreadline -lqreadline

# ..and comment those lines for linking against the static lib
HEADERS += ../../qreadline/*.h
SOURCES += ../../qreadline/*.cpp



HEADERS += mainwindow.h
SOURCES += main.cpp
SOURCES += mainwindow.cpp

MOC_DIR     = tmp
OBJECTS_DIR = tmp
