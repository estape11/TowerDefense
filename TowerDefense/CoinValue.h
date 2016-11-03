#ifndef COINVALUE_H
#define COINVALUE_H



#include <QGraphicsTextItem>

class CoinValue: public QGraphicsTextItem{
public:
    CoinValue(QGraphicsItem * parent=0);
    void increase();
    int getCoins();
private:
    int coins;
};

#endif // COINVALUE_H
