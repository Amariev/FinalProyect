#ifndef ENEMY_H
#define ENEMY_H

#include "personaje.h"

class Enemy : public Personaje {
    protected:
        bool alive;

    public:
        Enemy();

        Enemy(Coord pos, std::string symbol, int lives = 1, bool alive = true,
            int speed = 1);
        Enemy(Enemy &o);

        bool isAlive();
        void setAlive(bool alive);
        void printAttributes();
        void setRandomDirection();

};

class NormalEnemy : public Enemy {
    public:

        NormalEnemy(Coord, char, int lives, bool alive, int speed);
};

#endif
