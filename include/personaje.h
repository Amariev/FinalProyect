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
        char symbol;

      public:
        Personaje(int row, int col, char symbol, int lives = 1,
                  int speed = 1);

        Personaje(Personaje &o);

        void setSymbol(char);
        void setRow(int);
        void setCol(int);
        void setSpeed(int);
        void setLives(int);

        char getSymbol();
        int getRow();
        int getCol();
        int getSpeed();
        int getLives();

        void imprimirAtributos();
};
#endif
