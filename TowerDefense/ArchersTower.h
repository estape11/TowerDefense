#ifndef ARCHERSTOWER_H
#define ARCHERSTOWER_H

#include "Tower.h"
#include "Game.h"
#include <QTimer>
#include "Bullet.h"
#include<QMessageBox>
#include "iostream"
#include "stdio.h"
using namespace std;

class ArchersTower: public Tower{
    Q_OBJECT

public:
    ArchersTower(QGraphicsItem * parent=0);
    void upgrade();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void fire();
    int lvl;
    int getLvl() const;
    void setLvl(int value);
public slots:
    void aquire_target();
};

#endif // ARCHERSTOWER_H
