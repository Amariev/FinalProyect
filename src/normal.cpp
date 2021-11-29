#include "../include/basic.h"

Normal::Normal()
{
  ;
}

Normal::~Normal()
{
  ;
}

void Normal::update() {
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