#include <iostream>

class Level
{
   public: 
      int number;
      bool complete;
      int width;
      int height;
   
      Level (int number, int width, int height);

      void load_level();
      void change_level();
      void check_end_level();
      void load_player();
      void reset_game();
      // void complete();
      void draw();
};
