#include "BuildMagicianTower.h"
#include "Game.h"
#include "MagicianTower.h"
extern Game *game;

BuildMagicianTower::BuildMagicianTower(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    QPixmap icon (":/images/wizardTower.png");
    QPixmap resizeICOn = icon.scaled(QSize(50,50),Qt::IgnoreAspectRatio);
    setPixmap(QPixmap(resizeICOn));
}
void BuildMagicianTower::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!game->building){
        game->building= new MagicianTower();
        QPixmap to (":/images/wizardTower.png");
        QPixmap resizeTo = to.scaled(QSize(60,60),Qt::IgnoreAspectRatio);
        game->building->setPixmap(QPixmap(resizeTo));
        game->setCursor(QString(":/images/wizardTower.png"));
    }
}
