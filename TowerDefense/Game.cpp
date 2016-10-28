#include "Game.h"

Game::Game(): QGraphicsView(){

    QPixmap background(":/images/fnd_cesped.jpg");
    QPixmap resizeBackground = background.scaled(QSize(1200,660),  Qt::IgnoreAspectRatio);
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1200,660);
    setBackgroundBrush(QBrush(resizeBackground));

    // set the scene
    setScene(scene);

    // set cursor
    cursor = nullptr;
    building = nullptr;
    setMouseTracking(true);
    waves=50;

    initializeMapStatus();

    \
    // alter window
    setFixedSize(1200,660);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //play background music

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/backgroundSound.mp3"));
    music->setVolume(50);
    music->play();

    // set score
    score=new Score();
    score->setPos(1000,2);
    scene->addItem(score);
    coinValue=new CoinValue();
    coinValue->setPos(850,2);
    scene->addItem(coinValue);
    coin=new CoinImage();
    coin->setPos(810,15);
    scene->addItem(coin);

    createWave(waves);
    waves++;

    // test code
    BuildInfernalTowerIcon * in = new BuildInfernalTowerIcon();
    BuildArchersTower * ar = new BuildArchersTower();
    in->setPos(480,590);
    ar->setPos(580,590);
    scene->addItem(in);
    scene->addItem(ar);

    Castle* castle= new Castle();
    castle->setPos(0,0);
    scene->addItem(castle);

}

void Game::setCursor(QString filename){
    // if there is already a cursor, remove it first
    if (cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    QPixmap tower(filename);
    QPixmap resizeTower = tower.scaled(QSize(60,60),  Qt::KeepAspectRatio);
    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(resizeTower));
    scene->addItem(cursor);
    cursor->setPos((int(cursor->x())%60+int(cursor->x())),(int(cursor->y())%60+int(cursor->y())));


}

void Game::mouseMoveEvent(QMouseEvent *event){
    if (cursor){
        cursor->setPos(event->x(),event->y());
    }
}

void Game::mousePressEvent(QMouseEvent *event){
    // if we are building
    if (building){
        // return if the cursor is colliding with a tower
        QList<QGraphicsItem *> items = cursor->collidingItems();
        for (size_t i = 0, n = items.size(); i < n; i++){
            if (dynamic_cast<Tower*>(items[i])){
                return;
            }
        }

        // otherwise, build at the clicked location
        scene->addItem(building);
        building->setPos(event->x()-((event->x()%60)),(event->y()-((event->y()%60))));
        cout<<"Posicion de la Torre: x = "<<(building->x())<< "y=  " << building->y()<< endl;
        scene->removeItem(cursor);
        int x=(getCurrentBuildingPosX(building));
        cout<<x<<endl;
        int y=(getCurrentBuildingPosY(building));
        cout<<y<<endl;
        updateMapStatus(x,y,false);
        printMapStatus();
        cursor = nullptr;
        building = nullptr;
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }
}

void Game::createEnemies(int numberOfEnemies){
    enemiesSpawned=0;
    maxNumberOfEnemies= numberOfEnemies;
    connect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnTimer->start(1000);

}

void Game::createWave(int pwaves)
{
    // create enemy
    spawnTimer = new QTimer(this);
    enemiesSpawned=0;
    maxNumberOfEnemies=0;
    pointsToFollow << QPointF(1150,610) << QPointF(130,190);
    createEnemies(pwaves*2);
}

void Game::updateMapStatus(int i, int j, bool place)
{

    mapStatus[j][i]=place;

}

int Game::getCurrentBuildingPosX(Tower* building)
{
    return building->x()/60;
}
int Game::getCurrentBuildingPosY(Tower* building)
{
    return building->y()/60;
}

void Game::printMapStatus()
{
    for(int i=0;i<11;i++){
        for(int j=0;j<20;j++){
            cout<<(mapStatus[i][j]);
            cout<<" ";
        }
        cout<<""<<endl;
    }
}

void Game::initializeMapStatus()
{
    for(int i=0;i<11;i++){
        for(int j=0;j<20;j++){
            mapStatus[i][j]=true;
        }
    }
    cout<<"inicializado"<<endl;
    updateMapStatus(0,0,false);
    updateMapStatus(0,1,false);
    updateMapStatus(0,2,false);
    updateMapStatus(1,0,false);
    updateMapStatus(1,1,false);
    updateMapStatus(1,2,false);
    updateMapStatus(2,0,false);
    updateMapStatus(2,1,false);
    updateMapStatus(2,2,false);
    updateMapStatus(3,0,false);
    updateMapStatus(3,1,false);
    updateMapStatus(3,2,false);
    printMapStatus();
}

void Game::spawnEnemy(){
    //span an enemy
    Enemy* enemy=new Enemy(pointsToFollow);
    Mercenary* mercenary=new Mercenary(pointsToFollow);
    enemy->setPos(pointsToFollow[0]);
    mercenary->setPos(pointsToFollow[0]);
    scene->addItem(mercenary);
    scene->addItem(enemy);
    enemiesSpawned+=1;
    if (enemiesSpawned>=maxNumberOfEnemies){
       spawnTimer->disconnect();}
}
