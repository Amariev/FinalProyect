#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

struct Coord{int X, Y;};

class Object
{
    protected:
        std::string symbol;
        Coord pos;

      public:
        Object();
        Object(Coord, std::string);

        Object(Object &);

        void setSymbol(std::string);
        void setPos(Coord);

        std::string getSymbol();
        Coord getPos();

        virtual void printAttributes();
};

#endif