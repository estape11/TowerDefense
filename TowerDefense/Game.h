#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "Tower.h"
#include <QTimer>
#include "Score.h"
#include <QMediaPlayer>
#include <QGraphicsScene>
#include "InfernalTower.h"
#include "Enemy.h"
#include "BuildInfernalTowerIcon.h"
#include "BuildArchersTower.h"
#include "ArchersTower.h"
#include <QMediaPlayer>
#include <QUrl>
#include <QImage>
#include <QBrush>
#include "Castle.h"
#include <QGraphicsPixmapItem>
#include "Mercenary.h"
#include "iostream"
#include "stdio.h"
#include "CoinImage.h"
#include "CoinValue.h"
#include <QPushButton>
#include <QMessageBox>
#include "BuildMagicianTower.h"
#include "MagicianTower.h"
using namespace std;

class Game: public QGraphicsView{
    Q_OBJECT

public:
    // member functions
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void createEnemies(int numberOfEnemies);
    void createWave(int pwaves);
    void updateMapStatus(int i, int j, bool place);
    int getCurrentBuildingPosX(Tower* building);
    int getCurrentBuildingPosY(Tower* building);
    void printMapStatus();
    void initializeMapStatus();
    // member attributes
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Tower * building;
    Tower* building2;
    QTimer* spawnTimer;
    Score* score;
    CoinValue* coinValue;
    CoinImage* coin;
    int enemiesSpawned;
    int maxNumberOfEnemies;
    int waves;
    QList<QPointF> pointsToFollow;
    bool mapStatus[11][20];
    QPushButton* bFlag;
    void createButtom(int x, int y,Tower* pcursor);
    void printmessage();

public slots:
    void spawnEnemy();
    void handleButton();

};

#endif // GAME_H
