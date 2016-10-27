#include "Mercenary.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include "Game.h"
#include "stdio.h"
#include "iostream"
using namespace std;
extern Game * game;

Mercenary::Mercenary (QList<QPointF> pointsToFollow,QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
    // set graphics
        QPixmap orc(":images/hola.gif");
        QPixmap resizeOrc = orc.scaled(QSize(40,40), Qt::KeepAspectRatio);
        setPixmap(resizeOrc);}

    // set points
    points << pointsToFollow;
    point_index = 0;
    dest = points[0];
    destination=60;
    rotateToPoint(dest);

    //set variables
    life=10;
    xp=0;
    yp=0;

    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}

void Mercenary::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());}

void Mercenary::deleteEnemy(){
    scene()->removeItem(this);
    delete this;
}

void Mercenary::move_forward(){
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

//int Enemy::Pathfinding[](int x,int y)
//{
  //  game->mapStatus;
//}

////////////GETTERS & SETTERS///////////

int Mercenary::getLife() const{return life;}
void Mercenary::setLife(int value){life = value;}
int Mercenary::getXp() {return xp;}
int Mercenary::getYp(){return yp;}
void Mercenary::setXp(Mercenary* Mercenary){
    xp =Mercenary->x();
    //cout<<"x: " << xp<<endl;
                               }
void Mercenary::setYp(Mercenary* Mercenary){
    yp =Mercenary->y();
    //cout<<"y: " << yp<<endl;
                               }
