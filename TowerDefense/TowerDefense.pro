#-------------------------------------------------
#
# Project created by QtCreator 2016-10-10T16:34:56
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerDefense
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Enemy.cpp \
    InfernalTower.cpp \
    BuildInfernalTowerIcon.cpp \
    Bullet.cpp \
    Tower.cpp \
    Game.cpp \
    BuildArchersTower.cpp \
    ArchersTower.cpp \
    Score.cpp \
    Castle.cpp \
    Pathfinding.cpp \
    Mercenary.cpp \
    Ogres.cpp \
    CoinImage.cpp \
    CoinValue.cpp \
    BuildMagicianTower.cpp \
    MagicianTower.cpp \
    node.cpp \
    PathfindingAlgorithm.cpp \
    Elf.cpp \
    Harpy.cpp

HEADERS  += mainwindow.h \
    Enemy.h \
    InfernalTower.h \
    BuildInfernalTowerIcon.h \
    Bullet.h \
    Tower.h \
    Game.h \
    BuildArchersTower.h \
    ArchersTower.h \
    Score.h \
    Castle.h \
    Pathfinding.h \
    Mercenary.h \
    Ogres.h \
    CoinImage.h \
    CoinValue.h \
    BuildMagicianTower.h \
    MagicianTower.h \
    node.h \
    PathfindingAlgorithm.h \
    Elf.h \
    Harpy.h \
    ../../../cURL-POST/json.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
