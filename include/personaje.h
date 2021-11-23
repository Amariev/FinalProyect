#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <ctime>

struct Coord{int X, Y;
};
enum Directions {UP=1, DOWN, RIGHT, LEFT, STOP};

class Personaje
{
    protected:
        Coord pos;
        int lives;
        int speed;
        std::string symbol;
        Directions direction;

    public:
        Personaje();
        Personaje(Coord pos, std::string symbol, int lives = 1,
                  int speed = 1);

        Personaje(Personaje &o);

        void setSymbol(std::string);
        void setPos(Coord);
        void setSpeed(int);
        void setLives(int);
        void setDirection(Directions);

        std::string getSymbol();
        Coord getPos();
        int getSpeed();
        int getLives();
        Directions getDirection();

        void move();
        virtual void printAttributes();
};

#endif
