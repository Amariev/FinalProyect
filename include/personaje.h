#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <ctime>

struct Coord{int X, Y;};
enum Directions {UP=1, DOWN, RIGHT, LEFT, STOP};

class Personaje
{
    protected:
        int lives;
        int speed;
        std::string symbol;
        Directions direction;
        Coord pos;

    public:
        Personaje();
        Personaje(Coord pos, std::string symbol, int lives = 1,
                  int speed = 1);

        Personaje(Personaje &o);

        void setSymbol(std::string);
        void setSpeed(int);
        void setLives(int);
        void setDirection(Directions);
        void setPos(Coord);

        std::string getSymbol();
        int getSpeed();
        int getLives();
        Directions getDirection();
        Coord getPos();

        void move();
        virtual void printAttributes();
};

#endif
