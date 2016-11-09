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
#include "PathfindingAlgorithm.h"
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
    PathfindingAlgorithm * PF;
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
    int mapStatus[20][11];
    QPushButton* bFlag;

public slots:
    void spawnEnemy();

};

#endif // GAME_H
