#ifndef PLAYER_H
#define PLAYER_H

#include "personaje.h"
#include "../ext/conio.h"
#include <string>

class Player : public Personaje {
private: 
    int velocity;
    int levelScore;
    std::string name;
    int totalScore;
public:
    Player();

    Player(Coord, std::string symbol = "<>", int lives = 1,
           int level_score = 0, int total_score = 0);

    void setName(std::string);

    std::string getName();

    void printAttributes();

    void input();
    void update();
};
#endif
