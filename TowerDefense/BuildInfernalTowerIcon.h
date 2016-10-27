#ifndef BUILDINFERNALTOWERICON_H
#define BUILDINFERNALTOWERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildInfernalTowerIcon: public QGraphicsPixmapItem{
public:
    BuildInfernalTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BUILDINFERNALTOWERICON_H
