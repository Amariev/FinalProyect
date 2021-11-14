#include "../include/personaje.h"

// constructor
Personaje::Personaje(int row, int col, char symbol, int lives , int speed ) { // Personaje::row = row;
    Personaje::row = row;
    // this->row = row;
    Personaje::col = col;
    Personaje::symbol = symbol;

    Personaje::lives = lives;
    Personaje::speed = speed;
}

char Personaje::getSymbol() 
{
	return symbol;
}

void Personaje::setSymbol(char run) 
{
	symbol = run;
}

void Personaje::setRow(int row) 
{
    Personaje::row = row;
}

void Personaje::setCol(int col) 
{
    Personaje::col = col; 
}

void Personaje::setLives(int lives) 
{ 
    Personaje::lives = lives; 
}

void Personaje::setSpeed(int speed) 
{
    Personaje::speed = speed;
}

int Personaje::getRow()
{
	return row;
}

int Personaje::getCol() 
{ 
    return col; 
}

int Personaje::getLives() 
{ 
    return lives; 
}

int Personaje::getSpeed() 
{ 
    return speed; 
}
void Personaje::imprimirAtributos(){
    std::cout << "Row: " << row << std::endl;
    std::cout << "Col: "<< col << std::endl;
    std::cout << "Symbol: "<< symbol << std::endl;
    std::cout << "Lives: "<< lives << std::endl;
    std::cout << "Speed: "<< speed << std::endl;
}
