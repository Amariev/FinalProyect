#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "object.h"
#include <iostream>
#include <ctime>

enum Directions {UP=1, DOWN, RIGHT, LEFT, STOP};

class Personaje : public Object
{
    protected:
        int lives;
        Directions direction;

    public:
        Personaje();
        Personaje(Coord pos, std::string symbol, int lives = 1);

        Personaje(Personaje &o);

        void setLives(int);
        void setDirection(Directions);

        int getLives();
        Directions getDirection();

        void move();
        void printAttributes();
};

#endif
