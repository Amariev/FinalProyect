#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Maze {
public:
    int FParedes;

    Maze();
    void laberinto(int, int, int **);
    int ** getMaze();
};
#endif
