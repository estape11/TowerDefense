
#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "Tower.h"
#include <QTimer>
#include "Score.h"

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
    QTimer* spawnTimer;
    Score* score;
    int enemiesSpawned;
    int maxNumberOfEnemies;
    int waves;
    QList<QPointF> pointsToFollow;
    bool mapStatus[11][20];
    bool kind=true;

public slots:
    void spawnEnemy();

};

#endif // GAME_H
