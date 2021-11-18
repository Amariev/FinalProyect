#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "level.h"
#include "menu.h"

enum GameState {
    MENU = 0,
    RUN = 1,
    END = 2,
}; 

class Game
{
    public:
        int time;
        Level level;

        Game();
        ~Game();
        Game(int time);

        void run();

        GameState getState();
        void setState(GameState);

    private:
        GameState state;
        void clear_screen();
};
#endif
