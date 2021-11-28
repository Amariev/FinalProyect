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
        Coord oldPos;

    public:
        Personaje();
        Personaje(Coord pos, std::string symbol, int lives = 1);

        Personaje(Personaje &o);

        void setLives(int);
        void setDirection(Directions);
        void setOldPos(Coord);

        int getLives();
        Directions getDirection();
        Coord getOldPos();

        void move();
        void printAttributes();
};

#endif