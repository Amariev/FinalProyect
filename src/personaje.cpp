#include "../include/personaje.h"

// constructor
Personaje::Personaje(){}
Personaje::Personaje(int row, int col, char symbol, int lives,
                     int speed) { // Personaje::row = row;
  this -> row = row;
  // Personaje::row = row;
  this -> col = col;
  this -> symbol = symbol;

  this -> lives = lives;
  this -> speed = speed;
}

Personaje::Personaje(Personaje &o)
{
    row = o.row;
    col = o.col;
    lives = o.lives;
    speed = o.speed;
    symbol = o.symbol;
}

char Personaje::getSymbol() { return symbol; }

void Personaje::setSymbol(char run) { symbol = run; }

void Personaje::setRow(int row) { Personaje::row = row; }

void Personaje::setCol(int col) { Personaje::col = col; }

void Personaje::setLives(int lives) { Personaje::lives = lives; }

void Personaje::setSpeed(int speed) { Personaje::speed = speed; }

int Personaje::getRow() { return row; }

int Personaje::getCol() { return col; }

int Personaje::getLives() { return lives; }

int Personaje::getSpeed() { return speed; }
void Personaje::imprimirAtributos() {
  std::cout << "Row: " << row << std::endl;
  std::cout << "Col: " << col << std::endl;
  std::cout << "Symbol: " << symbol << std::endl;
  std::cout << "Lives: " << lives << std::endl;
  std::cout << "Speed: " << speed << std::endl;
}
