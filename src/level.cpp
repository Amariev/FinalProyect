#include "../include/level.h"
#include "../include/maze.h"
#include "../include/board.h"


Level::Level(int number, int width, int height) 
{
    this->number = number;
    this->width = width;
    this->height = height;
}


void Level::load_level() 
{
  Player player(2,2,'#');
  Enemy enemy(5,5,'t');

  Board *board = new Board(29, 19, player, enemy );
  board->inicializarMatriz();

  int **matrix = board->getBoard();
  int row = board->rows;
  int col = board->cols;

  Maze *maze = new Maze(matrix, row, col);
  maze->laberinto();
}


void Level::change_level()
{
    
}


void Level::check_end_level()
{
    
} 
