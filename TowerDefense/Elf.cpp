#include "Elf.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include "Game.h"
#include "stdio.h"
#include "iostream"
using namespace std;
extern Game * game;

Elf::Elf (QList<QPointF> pointsToFollow,QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
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

void Elf::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());}

void Elf::deleteEnemy(){
    scene()->removeItem(this);
    delete this;
}

void Elf::move_forward(){
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
}

void Elf::setAtributos(json eneJson){
    vida=eneJson["vida"];
    velocidad=eneJson["velocidad"];
    resisFlechas=eneJson["resisFlechas"];
    resisMagia=eneJson["resisMagia"];
    resisArti=eneJson["resisArti"];
}

////////////GETTERS & SETTERS///////////
int Elf::getXp() {return xp;}
int Elf::getYp(){return yp;}
void Elf::setXp(Elf* elf){xp =elf->x();}
void Elf::setYp(Elf* elf){yp =elf->y();}

int Elf::getVelocidad() const{return velocidad;}
void Elf::setVelocidad(int value){velocidad = value;}
int Elf::getResisMagia() const{return resisMagia;}
void Elf::setResisMagia(int value){resisMagia = value;}
int Elf::getResisFlechas() const{return resisFlechas;}
void Elf::setResisFlechas(int value){resisFlechas = value;}
int Elf::getResisArti() const{return resisArti;}
void Elf::setResisArti(int value){resisArti = value;}
int Elf::getVida() const{return vida;}
void Elf::setVida(int value){vida = value;}

