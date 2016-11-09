#ifndef INFERNALTOWER_H
#define INFERNALTOWER_H

#include "Tower.h"
#include "Game.h"
#include <QTimer>
#include "Bullet.h"
#include<QMessageBox>
#include "iostream"
#include "stdio.h"
using namespace std;

class InfernalTower: public Tower{
    Q_OBJECT

public:
    InfernalTower(QGraphicsItem * parent=0);
    void upgrade();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void fire();
    int lvl;
    int getLvl() const;
    void setLvl(int value);
    void askForUpgrade();


public slots:
    void aquire_target();
};

#endif // INFERNALTOWER_H
