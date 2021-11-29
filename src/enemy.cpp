#include "../include/basic.h"

Enemy::Enemy(){}
Enemy::~Enemy(){}

void Enemy::update(){}

void Enemy::setRandomDirection()
{
    int x = rand() % 4 + 1;
    switch (x) {
      case 1:
        this->direction = Direction::UP;
        break;
      case 2:
        this->direction = Direction::DOWN;
        break;
      case 3:
        this->direction = Direction::RIGHT;
        break;
      case 4:
        this->direction = Direction::LEFT;
        break;
    }
}
