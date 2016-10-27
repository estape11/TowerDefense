#ifndef OGRES_H
#define OGRES_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>

class Ogres: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ogres(QList<QPointF> pointsToFollow,QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
    void deleteEnemy();
    int getLife() const;
    void setLife(int value);
    //int Pathfinding[](int x,int y);
    int xp;
    int yp;
    void setYp(Ogres* ogres);
    void setXp(Ogres* ogres);
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

#endif // OGRES_H
