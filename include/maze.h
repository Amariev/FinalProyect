#include <iostream>
using namespace std;

class Maze {

public:
  int row;
  int col;
  int density;

  // maze(int, int,int);

  void inicializarMatriz();
  void laberinto();
  void drawMaze();
  // constructor
  Maze(int filas, int columnas, int densidad) {
    row = filas;
    col = columnas;
    density = densidad;
  }
};
