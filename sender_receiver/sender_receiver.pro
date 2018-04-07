TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sender.cpp \
    receiver.cpp \
    sere_interface.cpp

HEADERS += \
    sender.h \
    receiver.h \
    sere_interface.h

