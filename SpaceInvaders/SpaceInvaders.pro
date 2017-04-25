#-------------------------------------------------
#
# Project created by QtCreator 2017-04-18T13:32:38
#
#-------------------------------------------------

QT       += core gui quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpaceInvaders
TEMPLATE = app


SOURCES += main.cpp\
        mainmenu.cpp \
    gamewindow.cpp \
    spaceship.cpp \
    projectile.cpp \
    bunker.cpp \

HEADERS  += mainmenu.h \
    gamewindow.h \
    spaceship.h \
    projectile.h \
    bunker.h \

FORMS    += mainmenu.ui
