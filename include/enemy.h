#ifndef ENEMY
#define ENEMY

#include "personaje.h"

class Enemy : public Personaje {
public:
    bool alive;

    Enemy(int row, int col, char symbol, int lives = 1, bool alive = true, int speed = 1);
};
#endif
