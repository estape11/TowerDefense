#include "ArchersTower.h"


extern Game* game;

ArchersTower::ArchersTower(QGraphicsItem *parent)
{
    setLvl(1);
    // connect a timer to attack_target/aquire_target
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);

}

void ArchersTower::fire()
{
    //create the bullets
    Bullet * bullet1 = new Bullet();
    Bullet * bullet2 = new Bullet();
    Bullet * bullet3 = new Bullet();

    //set the sound of arrow
    QMediaPlayer * arrowsound = new QMediaPlayer();
    arrowsound->setMedia(QUrl("qrc:/sounds/fireSound.mp3"));
    arrowsound->setVolume(50);
    arrowsound->play();

    //set the graphics

    QPixmap fired(":/images/blueFire.png");
    QPixmap resizeFired = fired.scaled(QSize(40,40),  Qt::KeepAspectRatio);
    bullet1->setPixmap(QPixmap(resizeFired));
    bullet2->setPixmap(QPixmap(resizeFired));
    bullet3->setPixmap(QPixmap(resizeFired));

    bullet1->setPos(x()+44,y()+44);
    bullet2->setPos(x()+44,y()+44);
    bullet3->setPos(x()+44,y()+44);

    QLineF ln(QPointF(x()+44,y()+44),attack_dest);
    int angle = -1 * ln.angle();

    bullet1->setRotation(angle);
    bullet2->setRotation(angle+10);
    bullet3->setRotation(angle-10);

    game->scene->addItem(bullet1);
     game->scene->addItem(bullet2);
      game->scene->addItem(bullet3);
}


int ArchersTower::getLvl() const{return lvl;}

void ArchersTower::setLvl(int value){lvl = value;}

void ArchersTower::upgrade(){
    if(!game->building){
        int nextLvl=getLvl()+1;
        if (nextLvl>3){
            cout<<"Nivel Maximo Alcanzado"<<endl;
            return;
        }
        if(nextLvl==3){
            QPixmap icon(":/images/ArcherUpgrade.png");
            QPixmap resizeICon = icon.scaled(QSize(50,50),  Qt::IgnoreAspectRatio);
            setPixmap(QPixmap(resizeICon));
        }
        this->setLevel(nextLvl);
        setLvl(nextLvl);
        cout<<"se actualizo"<<endl;
        this->printing();
    }

}

void ArchersTower::mousePressEvent(QGraphicsSceneMouseEvent *event){this->upgrade();}
void ArchersTower::aquire_target(){Tower::aquire_target();}
