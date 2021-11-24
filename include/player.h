#ifndef PLAYER_H
#define PLAYER_H

#include "personaje.h"
#include "../ext/conio.h"

class Player : public Personaje {
private: 
    int velocity;
public:
    int level_score;
    std::string name;
    int total_score;
    int bulletCount;

    Player();

    Player(Coord pos, std::string symbol, int bulletCount = 5, int lives = 1,
           int speed = 1, int level_score = 0, int total_score = 0);
    void printAttributes();

    void input();
    
};
#endif
