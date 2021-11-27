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
  this->height = height_;
  this->width = width_;
  this->self = new int *[height_ + 2];

  for (int i = 0; i < height_ + 2; ++i)
    this->self[i] = new int[width_ + 2]{};
}

void Screen::draw(Entity *entity_)
{
  Coord coords = entity_->getCoords();
  this->self[coords.X][coords.Y] = entity_->getID();
}

void Screen::draw(std::string value_)
{
  std::cout << value_ << std::endl;
}

void Screen::display()
{
  usleep(500);
  std::cout << "\033[2J\033[1;1H";

  for (int i = 0; i < this->height + 2; i++) {
    for (int j = 0; j < this->width + 2; j++) {
      switch (this->self[i][j]) {
      case STONE:
        std::cout << ":3";
        break;
      default:
        std::cout << "  ";
        break;
      }
    }

    std::cout << "\n";
    }
}