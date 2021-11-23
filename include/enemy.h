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

        bool is_alive();
        void set_alive(bool alive);
        void printAttributes();

};

class Normal_Enemy : public Enemy {
    public:

        Normal_Enemy(Coord pos, char symbol, int lives = 1, bool alive = true, int speed = 1);
};

#endif
