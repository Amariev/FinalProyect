#include "../include/basic.h"

Player::Player()
{
  this->numberBombs = 0;
  this->usedBombs = 0;
  this->abilityCast = false;
}
 
Player::~Player() 
{
  delete [] bombs;
}

void Player::update() {
  this->lastPosition = position;
  if (kbhit()) 
    {
      switch (getch()) 
      {
        case 'w': 
        case 'W':
          this->direction = Direction::UP;
          break;
        case 's': 
        case 'S':
           this->direction = Direction::DOWN;
          break;
        break;
        case 'a': 
        case 'A':
          this->direction = Direction::LEFT;
          break;
        case 'd': 
        case 'D':
          this->direction = Direction::RIGHT;
          break;
        case 32: 
          this->castAbility();
          break;
        break;
      	default: break;
    }
  }
  
  this->move();
  this->direction = Direction::UNKNOWN;
}

void Player::castAbility()
{
  if (this->availableBombs > 0) {
    this->currentBombId = this->availableBombs - 1;

    this->abilityCast = true;
    this->availableBombs--;
    this->usedBombs++;
  }
}

void Player::setBombPosition(){
  int x = this->position.X;
  int y = this->position.Y;
  bombs[currentBombId].setActive(true);
  bombs[currentBombId].setPosition({x, y});
}

void Player::reloadBombs(int numberBombs_)
{
  this->numberBombs = numberBombs_;
  this->usedBombs = 0;
  this->availableBombs = this->numberBombs;
  this->currentBombId = this->availableBombs - 1; 
  this->bombs = new Bomb[this->numberBombs];
}
