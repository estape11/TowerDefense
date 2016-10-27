#include "BuildInfernalTowerIcon.h"
#include "Game.h"
#include "InfernalTower.h"
extern Game * game;

BuildInfernalTowerIcon::BuildInfernalTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap icon(":/images/ArtilleroGeneticKingdom.png");
    QPixmap resizeICon = icon.scaled(QSize(50,50),  Qt::KeepAspectRatio);
    setPixmap(QPixmap(resizeICon));
    ;
}

void BuildInfernalTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->building){
        game->building = new InfernalTower(); 
        QPixmap to(":/images/ArtilleroGeneticKingdom.png");
        QPixmap resizeTo = to.scaled(QSize(60,60),  Qt::IgnoreAspectRatio);
        game->building->setPixmap(QPixmap(resizeTo));
        game->setCursor(QString(":/images/ArtilleroGeneticKingdom.png"));
}
}
