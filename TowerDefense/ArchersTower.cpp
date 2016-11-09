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




int ArchersTower::getLvl() const
{
    return lvl;
}

void ArchersTower::setLvl(int value){
    lvl = value;
}




void ArchersTower::upgrade(){
    if(!game->building){
        int nextLvl=getLvl()+1;
        this->setLevel(nextLvl);
        setLvl(nextLvl);
        cout<<"se actualizo"<<endl;
        this->printing();
    }

}

void ArchersTower::askForUpgrade(){
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


void ArchersTower::mousePressEvent(QGraphicsSceneMouseEvent *event){this->askForUpgrade();}
void ArchersTower::aquire_target(){Tower::aquire_target();}
