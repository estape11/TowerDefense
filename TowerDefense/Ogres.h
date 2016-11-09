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
    //int Pathfinding[](int x,int y);
    int xp;
    int yp;
    void setYp(Ogres* ogres);
    void setXp(Ogres* ogres);
    int getYp();
    int getXp() ;

    int getVida() const;
    void setVida(int value);

    int getResisArti() const;
    void setResisArti(int value);

    int getResisFlechas() const;
    void setResisFlechas(int value);

    int getResisMagia() const;
    void setResisMagia(int value);

    int getVelocidad() const;
    void setVelocidad(int value);

public slots:
    void move_forward();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
    int destination;
    int vida;
    int resisArti;
    int resisFlechas;
    int resisMagia;
    int velocidad;
};

#endif // OGRES_H
