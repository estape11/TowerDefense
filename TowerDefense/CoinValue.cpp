#include "CoinValue.h"
#include <QFont>

CoinValue::CoinValue(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    coins = 0;

    // draw the text
    setPlainText(QString(" : ") + QString::number(coins)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",26));
}

void CoinValue::increase(){
    coins++;
    setPlainText(QString(" : ") + QString::number(coins)); // Score: 1
}

int CoinValue::getCoins(){
    return coins;
}

