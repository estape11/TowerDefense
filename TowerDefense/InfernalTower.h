#ifndef INFERNALTOWER_H
#define INFERNALTOWER_H

#include "Tower.h"

class InfernalTower: public Tower, public QString{
    Q_OBJECT

public:
    InfernalTower(QGraphicsItem * parent=0);
    void fire();
    void printMEE();
    int lvl;
    int upgradeCost;
    int nextlvl;

    void printmessage();

    int getUpgradeCost() const;
    void setUpgradeCost(int value);

    int getLvl() const;
    void setLvl(int value);

    int getNextlvl() const;
    void setNextlvl(int value);

public slots:
    void aquire_target();
};

#endif // INFERNALTOWER_H
