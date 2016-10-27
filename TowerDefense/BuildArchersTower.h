#ifndef BUILDARCHERSTOWER_H
#define BUILDARCHERSTOWER_H


#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildArchersTower: public QGraphicsPixmapItem{
public:
    BuildArchersTower(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUILDARCHERSTOWER_H
