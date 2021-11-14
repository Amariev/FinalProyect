#include <iostream>

class Maze
{
    int columnas;
    int filas;
    // int densidad;
    int **matriz;

public:
    Maze ();
    Maze (int columnas, int filas);
    void inicializarMatriz();
    void laberinto();
    void drawMaze();
    // ~Maze (); 
    int den = filas * columnas/4;
    const int FParedes  = 8;
};
