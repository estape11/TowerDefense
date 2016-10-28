#include "Ogres.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include "Game.h"
#include "stdio.h"
#include "iostream"
using namespace std;
extern Game * game;

Ogres::Ogres (QList<QPointF> pointsToFollow,QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
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
    life=10;
    xp=0;
    yp=0;

    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}

void Ogres::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());}

void Ogres::deleteEnemy(){
    scene()->removeItem(this);
    delete this;
}

void Ogres::move_forward(){
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

int Ogres::getLife() const{return life;}
void Ogres::setLife(int value){life = value;}
int Ogres::getXp() {return xp;}
int Ogres::getYp(){return yp;}
void Ogres::setXp(Ogres* ogres){
    xp =ogres->x();
    //cout<<"x: " << xp<<endl;
                               }
void Ogres::setYp(Ogres* ogres){
    yp =ogres->y();
    //cout<<"y: " << yp<<endl;
                               }
