#include "../include/basic.h"

Interface::Interface(Player * & player_) : player (player_)
{
  ;
}

Interface::~Interface()
{
  for(auto b : buttons){
    if(b!=nullptr) delete b;
  }
  buttons.clear();
}

void Interface::draw(Screen & screen_)
{
  ;
}

void Interface::update()
{
  ;
}
