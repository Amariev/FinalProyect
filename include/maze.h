<<<<<<< HEAD
#include <iostream>

class Maze{

    public:
    int row;
    int col;
    int density;

    Maze(int, int,int);

    void inicializarMatriz();
    void laberinto();
    void drawMaze();
};
//constructor 
Maze::Maze(int filas,int columnas, int densidad)
{
    row = filas;
    col = columnas;
    density = densidad;
}

//Métodos
=======
#include <iostream>

class Maze{

    public:
    int row;
    int col;
    int density;

    // maze(int, int,int);

    void inicializarMatriz();
    void laberinto();
    void drawMaze();
//constructor 
    Maze(int filas,int columnas, int densidad)
{
    row = filas;
    col = columnas;
    density = densidad;
}

//Métodos
};
>>>>>>> b778493f6433b39311c8badd3da7bf361552fc59
