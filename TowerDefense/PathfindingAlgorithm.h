#ifndef PATHFINDINGALGORITHM_H
#define PATHFINDINGALGORITHM_H
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include "node.h"
using namespace std;

static const int n=20; // horizontal size of the map
static const int m=11; // vertical size size of the map
static int Map[n][m];
static int closed_nodes_map[n][m]; // map of closed (tried-out) nodes
static int open_nodes_map[n][m]; // map of open (not-yet-tried) nodes
static int dir_map[n][m]; // map of directions
const int dir=8; // number of possible directions to go at any position
// if dir==4
//static int dx[dir]={1, 0, -1, 0};
//static int dy[dir]={0, 1, 0, -1};
// if dir==8
 const int dx[8]={1, 1, 0, -1, -1, -1, 0, 1};
 const int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};

class PathfindingAlgorithm
{
public:

     PathfindingAlgorithm();
     void printMap();

     int pathFinding (int xS, int yS, int xF, int yF, int gameMap[20][11]);

    // A-star algorithm.
    // The route returned is a string of direction digits.
    string pathFind( const int & xStart, const int & yStart,const int & xFinish, const int & yFinish );
};

#endif // PATHFINDINGALGORITHM_H
