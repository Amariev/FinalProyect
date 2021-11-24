#ifndef LEVEL_H
#define LEVEL_H

#include "../ext/conio.h"
#include "board.h"

#include <iostream>

class Level
{
   public: 
        int number;
        bool complete;
        int width, height;
        Board *board = nullptr;

        Level();
        ~Level();

        void load_level();
        void change_level();
        void check_end_level();
        void reset_game();
        // void complete();
        void draw();
};
#endif
