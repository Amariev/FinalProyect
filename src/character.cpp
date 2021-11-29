#include "../include/basic.h"

Character::Character() { ; }
Character::~Character() { ; }

void Character::draw() { ; }

void Character::move() 
{
  this->lastPosition = position;
  switch (direction) 
  {
    case Direction::UP:
      position.Y --;
      break;
    case Direction::DOWN:
      position.Y ++;
      break;
    case Direction::RIGHT:
      position.X ++;
      break;
    case Direction::LEFT:
      position.X --;
      break;
    default:
      break;
  }
}

void Character::update()
{
  this->lastPosition = position;
  switch (this->direction) 
  {
    case Direction::UP:
      this->position.Y--;
      break;
    case Direction::DOWN:
      this->position.Y++;
      break;
    case Direction::LEFT:
      this->position.X--;
      break;
    case Direction::RIGHT:
      this->position.X++;
      break;
    default: break;
   }

}