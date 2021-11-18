#include "../include/enemy.h"

// class Enemy
Enemy::Enemy(){}
Enemy::Enemy(int row, int col, std::string symbol, int lives, bool alive, int speed) : Personaje(row, col, symbol, lives, speed){
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
void Enemy::imprimirAtributos()
{
  std::cout << "Row: " << row << std::endl;
  std::cout << "Col: " << col << std::endl;
  std::cout << "Symbol: " << symbol << std::endl;
  std::cout << "Lives: " << lives << std::endl;
  std::cout << "Speed: " << speed << std::endl;
  std::cout << "Alive: " << alive << std::endl;
}
