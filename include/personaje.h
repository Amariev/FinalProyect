#ifndef PERSONAJE_H
#define PERSONAJE_H


#include <iostream>

class Personaje
{
    protected:
        int row;
        int col;
        int lives;
        int speed;
        std::string symbol;

      public:
        Personaje();
        Personaje(int row, int col, std::string symbol, int lives = 1,
                  int speed = 1);

        Personaje(Personaje &o);

        void setSymbol(std::string);
        void setRow(int);
        void setCol(int);
        void setSpeed(int);
        void setLives(int);

        std::string getSymbol();
        int getRow();
        int getCol();
        int getSpeed();
        int getLives();

        void imprimirAtributos();
};
#endif
