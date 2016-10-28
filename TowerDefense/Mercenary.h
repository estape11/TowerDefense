#ifndef MERCENARY_H
#define MERCENARY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>

class Mercenary: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Mercenary(QList<QPointF> pointsToFollow,QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
    void deleteEnemy();
    int getLife() const;
    void setLife(int value);
    //int Pathfinding[](int x,int y);
    int xp;
    int yp;
    void setYp(Mercenary* mercenary);
    void setXp(Mercenary* mercenary);
    int getYp();
    int getXp() ;

public slots:
    void move_forward();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
    int destination;
    int life;

};

#endif // MERCENARY_H
