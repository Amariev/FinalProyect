#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>

#include "../include/maze.h"
#include "../include/board.h"
#include "../include/player.h"
#include "../include/enemy.h"

class Level
{
   public: 
      int number;
      bool complete;
      int width;
      int height;
      int time;
      Board board;
   
      Level();
      Level (int number, int width, int height);

      void load_level();
      void change_level();
      void check_end_level();
      void load_player();
      void reset_game();
      // void complete();
      void draw();
};
#endif