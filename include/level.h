#ifndef LEVEL_H
#define LEVEL_H

#include "../ext/conio.h"
#include "board.h"

#include <iostream>

class Level
{
   public: 
        int number;
        bool complete, end;
        int width, height, numberEnemies;
        Board *board;

        Level();
        ~Level();

        void load_level();
        void change_level();
        void check_end_level();
        void reset_game();
        bool ended();

        bool draw();
};
#endif
