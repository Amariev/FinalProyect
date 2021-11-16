#include <iostream>

class Board
{
public:
    int cols;
    int rows;
    int **matrix;

    Board(int columnas, int filas);
    void inicializarMatriz();
    int **getBoard() { return this->matrix; }
    void drawBoard();
};
