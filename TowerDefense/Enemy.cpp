#include "Enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include "Game.h"
extern Game * game;

Enemy::Enemy (QList<QPointF> pointsToFollow,bool kind, QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
    // set graphics
    if (kind==true){
    QPixmap orc(":images/orc.png");
    QPixmap resizeOrc = orc.scaled(QSize(40,40), Qt::KeepAspectRatio);
    setPixmap(resizeOrc);}

    else{
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

void Enemy::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());}

void Enemy::deleteEnemy(){
    scene()->removeItem(this);
    delete this;
}

void Enemy::move_forward(){
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

int Enemy::getLife() const{return life;}
void Enemy::setLife(int value){life = value;}
int Enemy::getXp() {return xp;}
int Enemy::getYp(){return yp;}
void Enemy::setXp(Enemy* enemy){xp = enemy->x();}
void Enemy::setYp(Enemy* enemy){yp =enemy->y();}
