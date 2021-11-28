#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "level.h"
#include "menu.h"
#include "register.h"
#include <ctime>

#include "../provider/database.h"

enum GameState {
    MENU = 0,
    RUN = 1,
    END = 2,
}; 

class Game
{
    private:
      Level level; 
      Database<Register> *registerDb;

    public:
        //Level level; // private
        Game();
        ~Game();
        
        void run();

        GameState getState();
        void setState(GameState);
        void delay(int);
        GameState state;
        void clearScreen();
        void input();

        void save();
};
#endif