#ifndef LEVEL_H
#define LEVEL_H

#include "../ext/conio.h"
#include "../include/board.h"

#include <iostream>

class Level
{
   public: 
        int number;
        bool complete;
        int time;
        Board *board = new Board;

        Level();
        ~Level();
        Level (int number);

        void load_level();
        void change_level();
        void check_end_level();
        void reset_game();
        // void complete();
        void draw();
};
#endif
