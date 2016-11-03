#ifndef BUILDMAGICIANTOWER_H
#define BUILDMAGICIANTOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>


class BuildMagicianTower: public QGraphicsPixmapItem
{
public:
    BuildMagicianTower(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDMAGICIANTOWER_H
