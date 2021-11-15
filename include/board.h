#include <iostream>

class Board
{
public:
    int columnas;
    int filas;
    int **matriz;

    Board(int columnas, int filas);
    void inicializarMatriz();
    int **getBoard() { return this->matriz; }
    void drawBoard();
};
