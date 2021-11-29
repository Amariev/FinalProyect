#include "../include/basic.h"

Player::Player(int numberBombs_): numberBombs(numberBombs_)
{
  this->bombs = new Bomb[this->numberBombs];
  this->usedBombs = 0;
  this->availableBombs = this->numberBombs;
  this->currentBombId = this->availableBombs - 1; 
}

Player::~Player()
{
  ;
}

void Player::update() {
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

bool Player::castAbility()
{
  if (this->availableBombs > 0) {
    if (this->availableBombs) {
      this->currentBombId = this->availableBombs - 1;
    }

    this->abilityCast = true;
    this->availableBombs--;
    this->usedBombs++;
  }
}

void Player::setBombPosition(){
  int x = this->position.X;
  int y = this->position.Y;
  bombs[currentBombId].setActive(true);
  switch(direction){
    case Direction::UP:
      bombs[currentBombId].setPosition({x, y-1});
      break;
    case Direction::DOWN:
      bombs[currentBombId].setPosition({x, y+1});
      break;
    case Direction::RIGHT:
      bombs[currentBombId].setPosition({x+1, y});
      break;
    case Direction::LEFT:
      bombs[currentBombId].setPosition({x-1, y-1});
      break;
      default: break;
  }
}