#include "Harpy.h"

#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include "Game.h"
#include "stdio.h"
#include "iostream"
using namespace std;
extern Game * game;

Harpy::Harpy (QList<QPointF> pointsToFollow,QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
    // set graphics
        QPixmap orc(":images/hola.gif");
        QPixmap resizeOrc = orc.scaled(QSize(40,40), Qt::KeepAspectRatio);
        setPixmap(resizeOrc);

    // set points
    points << pointsToFollow;
    point_index = 0;
    dest = points[0];
    destination=60;
    rotateToPoint(dest);

    //set variables
    xp=0;
    yp=0;

    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}

void Harpy::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());}

void Harpy::deleteEnemy(){
    scene()->removeItem(this);
    delete this;
}

void Harpy::move_forward(){
    // if close to dest, rotate to next dest
    QLineF ln(pos(),dest);
    if (ln.length() < 5){
        point_index++;
        // last point reached
        if (point_index >= points.size()){return;}
        dest = points[point_index];
        rotateToPoint(dest);
    }
    // move enemy forward at current angle
    int STEP_SIZE = 10;
    double theta = rotation(); // degrees
    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
    setXp(this);
    setYp(this);

    //points.append(QPointF(1090-destination,540-destination));
    //destination+=60;
}

int Harpy::getVelocidad() const
{
    return velocidad;
}

void Harpy::setVelocidad(int value)
{
    velocidad = value;
}

int Harpy::getResisMagia() const
{
    return resisMagia;
}

void Harpy::setResisMagia(int value)
{
    resisMagia = value;
}

int Harpy::getResisFlechas() const
{
    return resisFlechas;
}

void Harpy::setResisFlechas(int value)
{
    resisFlechas = value;
}

int Harpy::getResisArti() const
{
    return resisArti;
}

void Harpy::setResisArti(int value)
{
    resisArti = value;
}

int Harpy::getVida() const
{
    return vida;
}

void Harpy::setVida(int value)
{
    vida = value;
}


////////////GETTERS & SETTERS///////////
int Harpy::getXp() {return xp;}
int Harpy::getYp(){return yp;}
void Harpy::setXp(Harpy* harpy){xp =harpy->x();}
void Harpy::setYp(Harpy* harpy){yp =harpy->y();}
