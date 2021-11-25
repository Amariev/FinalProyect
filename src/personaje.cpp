#include "../include/personaje.h"

// constructor

Personaje::Personaje(){}

Personaje::Personaje(Coord _pos, std::string _symbol, int _lives):Object(_pos, _symbol)
{ 
    this->pos = _pos;
    this -> symbol = _symbol;
    this -> lives = _lives;
    this->direction = Directions::STOP;
}

Personaje::Personaje(Personaje &o) : Object(o) {
    pos = o.pos;
    lives = o.lives;
    symbol = o.symbol;
}

// *********** SETTERS****************

void Personaje::setLives(int lives) { this->lives = lives; }

void Personaje::setDirection(Directions _direction) { this->direction = _direction;}

void Personaje::setOldPos(Coord currentPos) { this->oldPos = currentPos; }

// *********** GETTERS****************
int Personaje::getLives() { return lives; }

Directions Personaje::getDirection() { return direction; }

Coord Personaje::getOldPos() { return oldPos; }
//

void Personaje::move() {
  switch (direction) {
  case Directions::UP:
    pos.Y --;
    break;
  case Directions::DOWN:
    pos.Y ++;
    break;
  case Directions::RIGHT:
    pos.X ++;
    break;
  case Directions::LEFT:
    pos.X --;
    break;
  default:
    break;
  }
}

void Personaje::printAttributes() {
    Object::printAttributes();
    std::cout << "Lives: " << lives << std::endl;
    std::cout << "Direction: " << direction << std::endl;
}
