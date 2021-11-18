#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "../include/player.h"
#include "../include/enemy.h"

#define RED "\e[0;31m"

class Board
{
public:
    int cols;
    int rows;
    int **matrix;
    Player player;
    Enemy enemy;

    Board(int columnas, int filas, Player _player, Enemy _enemy);
    ~Board();
    void inicializarMatriz();
    int **getBoard() { return this->matrix; }
    void drawBoard();
    
};
#endif
