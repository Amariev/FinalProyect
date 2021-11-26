#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "colors.h"
#include "../include/player.h"
#include "../include/enemy.h"
#include "object.h"

enum material {
  EMPTY,
  WALL,
  PLAYER,
  ENEMY,
  HABILITY
};

class Board
{
public:
    int cols;
    int rows;
    int **matrix;
    int numNormalE;
    NormalEnemy *enemyN;
    Player player;

    Board();
    Board(int, int, int);
    ~Board();

    void generateMatrix();
    void maze();
    void assignBox(Coord, material);
    void assignEnemyBox();
    void checkCollisionPlayer();
    void checkCollisionEnemy();
    void draw();
    void update();

    void initializeEnemies();
};
#endif
