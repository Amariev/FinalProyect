#include <iostream>
#include "board.h"
#include "maze.h"

enum GameState {
    MENU = 0,
    RUN = 1,
    END = 2, 
}; 

class Game
{
    public:
        int time;

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
