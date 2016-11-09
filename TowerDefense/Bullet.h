#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include "Game.h"
#include <QList>
#include "Enemy.h"
#include <typeinfo>
#include "stdio.h"
#include "iostream"
#include "CoinValue.h"
#include "Elf.h"
#include "Mercenary.h"
#include "Ogres.h"
#include "Harpy.h"

using namespace std;


class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
    int STEP_SIZE;
    int power;
public slots:
    void move();
    double getMaxRange();
    double getDistanceTravelled();
    void setMaxRange(double rng);
    void setDistanceTravelled(double dist);    

private:
    double maxRange;
    double distanceTravelled;

};

#endif // BULLET_H
