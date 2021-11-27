#include "../include/basic.h"

Screen::Screen()
{
  ;
}

Screen::~Screen()
{
  ;
}

void Screen::create(int width_, int height_, std::string name_)
{
  this->name = name_;
  this->self = new int *[height_ + 2];

  for (int i = 0; i < height_ + 2; ++i)
    this->self[i] = new int[width_ + 2]{};
}

void Screen::draw(std::string value_)
{
  std::cout << value_ << std::endl;
}

void Screen::display()
{
  usleep(500);
  std::cout << "\033[2J\033[1;1H";
}