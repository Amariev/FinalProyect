#include <iostream>

class maze{

    public:
    int row;
    int col;
    int density;

    maze(int, int,int);

    void inicializarMatriz();
    void laberinto();
    void drawMaze();
};
//constructor 
maze::maze(int filas,int columnas, int densidad)
{
    row = filas;
    col = columnas;
    density = densidad;
}

//Métodos
