#include "Castle.h"
#include "BuildArchersTower.h"
#include "Game.h"
#include "ArchersTower.h"
extern Game * game;

Castle::Castle(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap icon(":/images/CastleBridge.png");
    QPixmap resizeICon = icon.scaled(QSize(240,180), Qt::IgnoreAspectRatio);
    setPixmap(QPixmap(resizeICon));

}



