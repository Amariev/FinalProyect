#include "../include/register.h"

Register::Register(string _name, int _score)
{
  setName(_name);
  setScore(_score);
}

void Register::setName(string name)
{
  this -> name = name;
}

void Register::setScore(int score)
{
  this-> score = score;
}

void Register::getName()
{
  cout<< "Nombre: " << name<<endl;
}

void Register::getScore()
{
  cout<< "Puntaje: "<< score << endl;
}