#include "InfernalTower.h"
#include "Game.h"
#include <QTimer>
#include "Bullet.h"
#include <QMessageBox>
#include <QString>
#include "QString"
extern Game* game;

InfernalTower::InfernalTower(QGraphicsItem *parent)
{
    // connect a timer to attack_target/aquire_target
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
    lvl=1;
    upgradeCost= 150;
    nextlvl=2;
}

void InfernalTower::fire()
{
    //set the sound of shoot
    QMediaPlayer * shootsound = new QMediaPlayer();
    shootsound->setMedia(QUrl("qrc:/sounds/shootsound.mp3"));
    shootsound->setVolume(50);
    shootsound->play();

    QPixmap fired(":/images/bala2.png");
    QPixmap resizeFired = fired.scaled(QSize(40,40),  Qt::KeepAspectRatio);
    Bullet * bullet = new Bullet();
    bullet->setPixmap(QPixmap(resizeFired));
    bullet->setPos(x()+44,y()+44);

    QLineF ln(QPointF(x()+44,y()+44),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void InfernalTower::printMEE(){cout<<"METODO DE INFERNAL"<<endl;}

int InfernalTower::getNextlvl() const
{
    return nextlvl;
}

void InfernalTower::setNextlvl(int value)
{
    nextlvl = value;
}

void InfernalTower::aquire_target()
{
   Tower::aquire_target();
}

int InfernalTower::getLvl() const
{
    return lvl;
}

void InfernalTower::setLvl(int value)
{
    lvl = value;
}

int InfernalTower::getUpgradeCost() const
{
    return upgradeCost;
}

void InfernalTower::setUpgradeCost(int value)
{
    upgradeCost = value;
}


void InfernalTower::printmessage(){

    QMessageBox msgBox;
    msgBox.setWindowTitle("title");
    msgBox.setText("Question");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if (msgBox.exec()== QMessageBox::Yes){
        cout<<"eleccion si"<<endl;
        if (upgradeCost >= upgradeCost){
              cout<<"es igualo mayor"<<endl;
        }
        else{
            cout<<"es menor"<<endl;
        }
    }
    else{
        cout<<"Eleccion no"<<endl;
    }
}


