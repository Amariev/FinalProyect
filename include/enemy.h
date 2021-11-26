#ifndef ENEMY_H
#define ENEMY_H

#include "personaje.h"

class Enemy : public Personaje {
    protected:
        bool alive;

    public:
        Enemy();

        Enemy(Coord pos, int lives = 1, 
                bool alive = true);
        Enemy(Enemy &o);

        bool isAlive();
        void setAlive(bool alive);
        void setRandomDirection();
        void printAttributes();

};

class NormalEnemy : public Enemy {
    public:
      NormalEnemy();
      NormalEnemy(Coord, int lives, bool alive);
};

#endif
