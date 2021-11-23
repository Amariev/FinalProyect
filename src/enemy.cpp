#include "../include/enemy.h"

// class Enemy
Enemy::Enemy(){}
Enemy::Enemy(Coord pos, std::string symbol, int lives, bool alive, int speed) : Personaje(pos, symbol, lives, speed){
    Enemy::alive = alive;
};

Enemy::Enemy(Enemy &o) : Personaje(o) 
{
    alive = o.alive;
}

bool Enemy::is_alive()
{
    return alive;
}

void Enemy::set_alive(bool alive) 
{
    this->alive = alive;
}

void Enemy::printAttributes()
{
    Personaje::printAttributes();
    std::cout << "Alive: " << alive << std::endl;
}
