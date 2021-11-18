#ifndef PLAYER_H
#define PLAYER_H

#include "personaje.h"

enum Directions {UP=1, DOWN, RIGHT, LEFT, IDLE};

class Player : public Personaje {
public:
    int level_score;
    std::string name;
    int total_score;
    int bulletCount;
    int width;
    int height;
    Directions direction;

    Directions getDirection();
    void setDirection(Directions);
    Player();
    Player(int row, int col, std::string symbol, int bulletCount = 5, int lives = 1,
           int speed = 1, int level_score = 0, int total_score = 0);
    void imprimirAtributos();
};
#endif
