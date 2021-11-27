#include "../include/basic.h"

Level::Level(Screen & screen_, Player *& player_) :
  screen(screen_), player(player_), interface(player_)
{
  ;
}

Level::~Level()
{
  ;
}

bool Level::play(Screen & screen_, Player *& player_)
{
  std::cout << "playing" << std::endl;
  // this->player = 
}