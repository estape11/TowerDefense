#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "iostream"
#include "stdio.h"
#include <QMessageBox>

using namespace std;

class Tower:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Tower(QGraphicsItem * parent=0);
    double distanceTo(QGraphicsItem * item);
    virtual void fire();

    float getSpeedAttack() const;
    void setSpeedAttack(float value);
    int getLevel() const;
    void setLevel(int value);
    void printing();
    void askForUpgrade();


public slots:
    void aquire_target();
protected:
    QGraphicsPolygonItem * attack_area;
    QPointF attack_dest;
    bool has_target;
    float speedAttack;
    int level;
};
#endif // TOWER_H
