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

void MagicianTower::mousePressEvent(QGraphicsSceneMouseEvent *event){this->upgrade();}

void MagicianTower::aquire_target(){Tower::aquire_target();}
