#include <iostream>

class Maze
{
    int columnas;
    int filas;
    // int densidad;
    int **matriz;

public:
  Maze();
    Maze(int columnas, int filas);
    /* Maze(int **matriz_) : matriz{matriz_} {
        filas = sizeof matriz_ / sizeof matriz_[0]; // 2 rows
        columnas = sizeof matriz_[0] / sizeof(int); // 5 cols
    }; */
    void inicializarMatriz();
    void laberinto();
    void drawMaze();
    // ~Maze (); 
    int den = filas * columnas/4;
    const int FParedes  = 8;
};
