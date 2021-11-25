#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "colors.h"
#include "../include/player.h"
#include "../include/enemy.h"

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
    Player player;
    Enemy enemy;

    Board();
    Board(int cols, int rows);
    ~Board();

    void generateMatrix();
    int **getBoard() { return this->matrix; }
    void assignBox(Coord, material);
    void checkCollisionPlayer();
    void checkCollisionEnemy();
    void draw();
    void update();

    void halt(Coord);
    void maze();
};
#endif
