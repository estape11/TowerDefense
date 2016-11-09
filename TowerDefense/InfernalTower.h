#ifndef INFERNALTOWER_H
#define INFERNALTOWER_H

#include "Tower.h"

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


public slots:
    void aquire_target();
};

#endif // INFERNALTOWER_H
