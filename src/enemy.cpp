#include "../include/enemy.h"

Enemy::Enemy(int row, int col, char symbol, int lives, bool alive, int speed) : Personaje(row, col, symbol, lives, speed){
    Enemy::alive = alive;
};
