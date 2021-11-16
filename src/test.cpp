#include "../include/board.h"
#include "../include/maze.h"

void test1()
{
    Board *board = new Board(29, 19);
    board->inicializarMatriz();
    int **matrix = board->getBoard();
    int row = board->filas;
    int col = board->columnas;
    Maze *maze = new Maze(matrix, row, col);
    maze->laberinto();
    board->drawBoard();
}

int main()
{
    test1();
    return 0;
}
