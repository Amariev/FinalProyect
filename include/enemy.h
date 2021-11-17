#ifndef ENEMY_H
#define ENEMY_H

#include "personaje.h"

class Enemy : public Personaje {
public:
    bool alive;

    Enemy(int row, int col, char symbol, int lives = 1, bool alive = true, int speed = 1);
};
#endif

class Normal_Enemy : public Enemy {
public:
    bool alive;

    Normal_Enemy(int row, int col, char symbol, int lives = 1, bool alive = true, int speed = 1);
};
