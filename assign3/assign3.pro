TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    phypages.c \
    pagetable.c \
    assign3part2.c

DISTFILES += \
    part1sequence \
    part1testsequence

HEADERS += \
    pagetable.h \
    phypages.h
