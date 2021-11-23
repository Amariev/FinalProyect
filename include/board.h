#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "colors.h"
#include "../include/player.h"
#include "../include/enemy.h"
#include "maze.h"

//#define RED "\e[0;31m"

class Board
{
public:
    int cols;
    int rows;
    //Maze maze;
    int **matrix;
    Player player;
    Enemy enemy;
    Maze maze;

    Board();
    Board(int cols, int rows);
    ~Board();

    void generateMatrix();
    int **getBoard() { return this->matrix; }
    void assignBox(Coord, int);
    void drawBoard();
    void update();

    void halt(Coord);
};
#endif
