#include "InfernalTower.h"
#include "Game.h"
#include <QTimer>
#include "Bullet.h"
#include <QMessageBox>
#include <QString>
#include "QString"
extern Game* game;


int InfernalTower::upgradeCost = 150;
InfernalTower::InfernalTower()
{
    // connect a timer to attack_target/aquire_target
    lvl = 1;
    int a = 150;
    InfernalTower::upgradeCost = a;
    nextlvl = 2;

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
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
    cout<<upgradeCost<<endl;
    return upgradeCost;
}

void InfernalTower::setUpgradeCost(int value)
{
    upgradeCost = value;
}


void InfernalTower::printmessage(){

    QMessageBox msgBox;
    msgBox.setWindowTitle("Upgrade");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setText("Do you want to upgrade this Tower to lvl ");
    msgBox.setInformativeText("It costs 150 gold");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if(msgBox.exec() == QMessageBox::Yes){
        cout<<typeid(this->upgradeCost).name()<<endl;
        cout<<game->coinValue->getCoins()<<endl;
        if(getUpgradeCost() <= game->coinValue->getCoins()){
            cout<<"listo"<<endl;
            QMessageBox info;
            info.setWindowTitle("Congrats !!");
            info.setIcon(QMessageBox::Information);
            info.setText("Successful progress update");
            info.exec();
        }

        else{
            QMessageBox info;
            info.setWindowTitle("Not enough gold");
            info.setIcon(QMessageBox::Information);
            info.setText("You dont have enough gold to upgrade this tower");
            info.setInformativeText("It costs  gold, and you have ");
            info.setStandardButtons(QMessageBox::Ok);
            info.setDefaultButton(QMessageBox::Ok);
            info.exec();
        }
    }
    else{
        cout<<"NO hizo upgrade"<<endl;
    }
}


