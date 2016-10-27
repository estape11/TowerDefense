#ifndef ARCHERSTOWER_H
#define ARCHERSTOWER_H


#include "Tower.h"

class ArchersTower: public Tower{
    Q_OBJECT

public:
    ArchersTower(QGraphicsItem * parent=0);
    void fire();
public slots:
    void aquire_target();
};

#endif // ARCHERSTOWER_H
