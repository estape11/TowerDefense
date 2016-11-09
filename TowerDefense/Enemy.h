#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include "Game.h"
#include "stdio.h"
#include "iostream"
using namespace std;

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QList<QPointF> pointsToFollow, QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
    void deleteEnemy();
    int getLife() const;
    void setLife(int value);
    //int Pathfinding[](int x,int y);
    int xp;
    int yp;
    void setYp(Enemy* enemy);
    void setXp(Enemy* enemy);
    int getYp();
    int getXp() ;

public slots:
    void move_forward();
protected:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
    int destination;
    int life;

};

#endif // ENEMY_H
