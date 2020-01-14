#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define UP 1
#define DOWN -1
#define LEFT 2
#define RIGHT -2

void initGrid(int, int);
void drawGrid();
void drawSquare(int,int);
void drawUnit(int x, int y, bool alive);
void drawCells();
void generateRandStart(int noOfAlive);
void checkState(int x, int y);
int liveNeighbours(int x, int y);

#endif

