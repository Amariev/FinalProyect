#include "../include/personaje.h"

// constructor

Personaje::Personaje(){}

Personaje::Personaje(Coord _pos, std::string _symbol, int _lives,
                     int _speed) { // Personaje::row = row;
    this->pos = _pos;
    this -> symbol = _symbol;
    this -> lives = _lives;
    this->speed = _speed;
    this->direction = Directions::STOP;
}

Personaje::Personaje(Personaje &o) {
    pos = o.pos;
    lives = o.lives;
    speed = o.speed;
    symbol = o.symbol;
}

// *********** SETTERS****************
void Personaje::setPos(Coord _pos) { this->pos = _pos; }

void Personaje::setSymbol(std::string _symbol) { this->symbol = _symbol; }

void Personaje::setLives(int lives) { this->lives = lives; }

void Personaje::setSpeed(int speed) { this->speed = speed; }

void Personaje::setDirection(Directions _direction) { this->direction = _direction; }

// *********** GETTERS****************
std::string Personaje::getSymbol() { return symbol; }

int Personaje::getLives() { return lives; }

int Personaje::getSpeed() { return speed; }

Coord Personaje::getPos() { return pos; }

Directions Personaje::getDirection() { return direction; }

//

/*
void Personaje::move() {
  switch (direction) {
  case Directions::UP:
    pos.Y -= speed;
    break;
  case Directions::DOWN:
    pos.Y += speed;
    break;
  case Directions::RIGHT:
    pos.X += speed;
    break;
  case Directions::LEFT:
    pos.X -= speed;
    break;
  default:
    break;
  }
}
*/

void Personaje::move() {
  if(direction == UP && getPos().Y > 1){
    pos.Y -= speed;
  }
  else if(direction == DOWN && getPos().Y < 15){
    pos.Y += speed;
  }
  else if(direction == RIGHT && getPos().X < 15){
    pos.X += speed;
  }
  else if(direction == LEFT && getPos().X > 1){
    pos.X-= speed;
  } 
}


void Personaje::printAttributes() {
  std::cout << "Symbol: " << symbol << std::endl;
  std::cout << "Lives: " << lives << std::endl;
  std::cout << "Speed: " << speed << std::endl;
}
