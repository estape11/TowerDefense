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

    int xp;
    int yp;
    void setYp(Mercenary* mercenary);
    void setXp(Mercenary* mercenary);
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

#endif // MERCENARY_H
