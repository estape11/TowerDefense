#include "MagicianTower.h"
#include "Bullet.h"
#include "Game.h"
#include <QTimer>

extern Game *game;

MagicianTower::MagicianTower(QGraphicsItem *parent){
    setLvl(1);
    QTimer *timer = new QTimer(this);
    connect (timer, SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void MagicianTower::fire(){

    QMediaPlayer *magicsound = new QMediaPlayer();
    magicsound->setMedia(QUrl("qrc:/sounds/MagicSound.mp3"));
    magicsound->setVolume(50);
    magicsound->play();

    QPixmap fired(":/images/blueFire.png");
    QPixmap resizeBall = fired.scaled(QSize(40,40), Qt::KeepAspectRatio);
    Bullet * bullet = new Bullet();
    bullet->setPixmap(QPixmap(resizeBall));
    bullet->setPos(x()+44,y()+44);


    QLineF ln(QPointF(x()+44,y()+44),attack_dest);
    int angle=-1 *ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}



int MagicianTower::getLvl() const
{
    return lvl;
}

void MagicianTower::setLvl(int value)
{
    lvl = value;
}



void MagicianTower::upgrade()
{
    if(!game->building){
        int nextLvl=getLvl()+1;
        this->setLevel(nextLvl);
        setLvl(nextLvl);
        cout<<"se actualizo"<<endl;
        this->printing();
    }

}
void MagicianTower::askForUpgrade(){
    QMessageBox msgBox;
         msgBox.setWindowTitle("Upgrade");
         msgBox.setIcon(QMessageBox::Question);
         msgBox.setText("Do you want to upgrade this Tower to lvl ");
         msgBox.setInformativeText("It costs 150 gold");
         msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
         msgBox.setDefaultButton(QMessageBox::No);
         if(msgBox.exec() == QMessageBox::Yes){
                 QMessageBox info;
                 info.setWindowTitle("Congrats !!");
                 info.setIcon(QMessageBox::Information);
                 info.setText("Successful progress update");
                 info.exec();
                 upgrade();
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

void MagicianTower::mousePressEvent(QGraphicsSceneMouseEvent *event){this->askForUpgrade();}

void MagicianTower::aquire_target(){Tower::aquire_target();}
