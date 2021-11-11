#include <iostream>

class Game
{
    public:
        int time;

        Game(int time);

        void menu();
        char input();
        void run();    
};