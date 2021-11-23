#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "level.h"
#include "menu.h"
#include "board.h"
#include <ctime>

enum GameState {
    MENU = 0,
    RUN = 1,
    END = 2,
}; 

class Game
{
    private:
      Level level; 
    public:       
        //Level level; // private
        Game();
        ~Game();
        
        void run();

        GameState getState();
        void setState(GameState);
        void delay(int);

    private:
        GameState state;
        void clearScreen();
};
#endif
