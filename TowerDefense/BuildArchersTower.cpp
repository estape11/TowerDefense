#include "BuildArchersTower.h"
#include "Game.h"
#include "ArchersTower.h"
extern Game * game;

BuildArchersTower::BuildArchersTower(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap icon(":/images/ArcherGeneticKingdom.png");
    QPixmap resizeICon = icon.scaled(QSize(50,50),  Qt::IgnoreAspectRatio);
    setPixmap(QPixmap(resizeICon));
    ;
}

void BuildArchersTower::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->building){
        game->building = new ArchersTower();
        QPixmap to(":/images/ArcherGeneticKingdom.png");
        QPixmap resizeTo = to.scaled(QSize(60,60),  Qt::IgnoreAspectRatio);
        game->building->setPixmap(QPixmap(resizeTo));
        game->setCursor(QString(":/images/ArcherGeneticKingdom.png"));
    }
}
