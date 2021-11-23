#ifndef PLAYER_H
#define PLAYER_H

#include "personaje.h"

class Player : public Personaje {
public:
    int level_score;
    std::string name;
    int total_score;
    int bulletCount;

    Directions getDirection();
    void setDirection(Directions);
    Player();
    Player(Coord pos, std::string symbol, int bulletCount = 5, int lives = 1,
           int speed = 1, int level_score = 0, int total_score = 0);
    void printAttributes();
};
#endif
