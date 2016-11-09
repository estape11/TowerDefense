#include "InfernalTower.h"

extern Game* game;



InfernalTower::InfernalTower(QGraphicsItem *parent)
{
    // connect a timer to attack_target/aquire_target
    setLvl(1);

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

void InfernalTower::upgrade(){
    if(!game->building){
        int nextLvl=getLvl()+1;
        if (nextLvl>3){
            cout<<"Nivel Maximo Alcanzado"<<endl;
            return;
        }
        if(nextLvl==3){
            QPixmap icon(":/images/ArtilleroUpgrade.png");
            QPixmap resizeICon = icon.scaled(QSize(50,50),  Qt::IgnoreAspectRatio);
            setPixmap(QPixmap(resizeICon));
        }
        this->setLevel(nextLvl);
        setLvl(nextLvl);
        cout<<"se actualizo"<<endl;
        this->printing();
    }

}


void InfernalTower::mousePressEvent(QGraphicsSceneMouseEvent *event){this->upgrade();}
