#ifndef MAGICIANTOWER_H
#define MAGICIANTOWER_H

#include "Tower.h"
#include "Game.h"
#include <QTimer>
#include "Bullet.h"
#include<QMessageBox>
#include "iostream"
#include "stdio.h"
using namespace std;


class MagicianTower: public Tower{
    Q_OBJECT
public:
    MagicianTower(QGraphicsItem *parent=0);
    void fire();
public slots:
    void aquire_target();
};

#endif // MAGICIANTOWER_H
