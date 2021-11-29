#include "../include/basic.h"

Player::Player()
{
  ;
}

Player::~Player()
{
  ;
}

void Player::update() {
  this->lastPosition = position;
  if (kbhit()) 
    {
      switch (getch()) 
      {
        case 'w': 
        case 'W':
          this->position.Y--;
          break;
        case 's': 
        case 'S':
          this->position.Y++;
          break;
        break;
        case 'a': 
        case 'A':
          this->position.X--;
          break;
        case 'd': 
        case 'D':
          this->position.X++;
          break;
        break;
      	default: break;
    }
  }
}

bool Player::castAbility()
{
  ;
}

Ability * Player::getAbility()
{
  Bomb * bomb = new Bomb;
  return bomb;
}
