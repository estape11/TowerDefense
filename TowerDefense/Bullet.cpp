#include "Bullet.h"

extern Game * game; //theres is an external global obect called game

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    // set graphics
    QPixmap fired(":/images/fireball.png");
    QPixmap resizeFired = fired.scaled(QSize(60,60),  Qt::KeepAspectRatio);
    setPixmap(QPixmap(resizeFired));

    // connect a timer to move()
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);

    // initialize values
    maxRange = 100;
    distanceTravelled = 0;
    power=1;
}

void Bullet::move(){
    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem*> colliding_items= collidingItems();
    for (int i=0, n= colliding_items.size(); i<n;i++){
        if (typeid(*(colliding_items[i]))==typeid(Enemy)){
            //increase the score
            Enemy* flag= dynamic_cast<Enemy*>(colliding_items[i]);
            flag->setLife(flag->getLife()-power);
            scene()->removeItem(this);
            delete this;
            if(flag->getLife()==0){
                flag->deleteEnemy();
                game->score->increase();
                game->coinValue->increase();
                return;
            }
   return;}
       else if (typeid(*(colliding_items[i]))==typeid(Elf)){
            //increase the score
            Elf* flag= dynamic_cast<Elf*>(colliding_items[i]);
            flag->setVida(flag->getVida()-power);
            scene()->removeItem(this);
            delete this;
            if(flag->getVida()==0){
                flag->deleteEnemy();
                game->score->increase();
                game->coinValue->increase();
                return;
            }
   return;}
        else if (typeid(*(colliding_items[i]))==typeid(Ogres)){
             //increase the score
             Ogres* flag= dynamic_cast<Ogres*>(colliding_items[i]);
             flag->setVida(flag->getVida()-power);
             scene()->removeItem(this);
             delete this;
             if(flag->getVida()==0){
                 flag->deleteEnemy();
                 game->score->increase();
                 game->coinValue->increase();
                 return;
             }
    return;}
        else if (typeid(*(colliding_items[i]))==typeid(Mercenary)){
             //increase the score
             Mercenary* flag= dynamic_cast<Mercenary*>(colliding_items[i]);
             flag->setVida(flag->getVida()-power);
             scene()->removeItem(this);
             delete this;
             if(flag->getVida()==0){
                 flag->deleteEnemy();
                 game->score->increase();
                 game->coinValue->increase();
                 return;
             }
    return;}
        else if (typeid(*(colliding_items[i]))==typeid(Harpy)){
             //increase the score
             Harpy* flag= dynamic_cast<Harpy*>(colliding_items[i]);
             flag->setVida(flag->getVida()-power);
             scene()->removeItem(this);
             delete this;
             if(flag->getVida()==0){
                 flag->deleteEnemy();
                 game->score->increase();
                 game->coinValue->increase();
                 return;
             }
    return;}

    }

    STEP_SIZE = 30;
    double theta = rotation(); // degrees
    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
    setPos(x()+dx, y()+dy);
    }


double Bullet::getMaxRange(){
    return maxRange;
}

double Bullet::getDistanceTravelled(){
    return distanceTravelled;
}

void Bullet::setMaxRange(double rng){
maxRange = rng;
}

void Bullet::setDistanceTravelled(double dist){
    distanceTravelled = dist;
}
