#include "CoinImage.h"
#include "Game.h"

extern Game * game;

CoinImage::CoinImage(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap coin(":/images/coin.png");
    QPixmap resizeCoin = coin.scaled(QSize(35,35), Qt::IgnoreAspectRatio);
    setPixmap(QPixmap(resizeCoin));

}



