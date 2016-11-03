#include "MagicianTower.h"

extern Game *game;

MagicianTower::MagicianTower(QGraphicsItem *parent){
    QTimer *timer = new QTimer(this);
    connect (timer, SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void MagicianTower::fire(){
    Bullet *bullet1 = new Bullet();
    Bullet *bullet2 = new Bullet();
    Bullet *bullet3 = new Bullet();

    QMediaPlayer *magicsound = new QMediaPlayer();
    magicsound->setMedia(QUrl(""));
    magicsound->setVolume(50);
    magicsound->play();

    QPixmap fired(":/image/blueFire.png");
    QPixmap resizeBall = fired.scaled(QSize(40,40), Qt::KeepAspectRatio);
    bullet1->setPixmap(QPixmap(resizeBall));
    bullet2->setPixmap(QPixmap(resizeBall));
    bullet3->setPixmap(QPixmap(resizeBall));

    bullet1->setPos(x()+44,y()+44);
    bullet2->setPos(x()+44,y()+44);
    bullet3->setPos(x()+44,y()+44);

    QLineF ln(QPointF(x()+44,y()+44),attack_dest);
    int angle=-1 *ln.angle();

    bullet1->setRotation(angle);
    bullet2->setRotation(angle+10);
    bullet3->setRotation(angle-10);

    game->scene->addItem(bullet1);
     game->scene->addItem(bullet2);
      game->scene->addItem(bullet3);
}


void MagicianTower::aquire_target(){Tower::aquire_target();}
