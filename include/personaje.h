#ifndef PERSONAJE_H
#define PERSONAJE_H


#include <iostream>

struct Coord{int X, Y; };

class Personaje
{
    protected:
        Coord pos;
        int lives;
        int speed;
        std::string symbol;

      public:
        Personaje();
        Personaje(Coord pos, std::string symbol, int lives = 1,
                  int speed = 1);

        Personaje(Personaje &o);

        void setSymbol(std::string);
        void setPos(Coord);
        void setSpeed(int);
        void setLives(int);

        std::string getSymbol();
        Coord getPos();
        int getSpeed();
        int getLives();

        virtual void printAttributes();
};

#endif
