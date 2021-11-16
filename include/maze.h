#include <iostream>
#include <cstdlib>
#include <ctime>

class Maze {
public:
    int **matrix;
    int const row;
    int const col;
    int den;
    int const FParedes = 8;

    Maze(int **matrix_, int col_, int row_);
    void laberinto();
    int ** getMaze();
};

