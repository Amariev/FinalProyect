#include "../include/basic.h"

NextLevel::NextLevel()
{
  ;
}

NextLevel::~NextLevel()
{
  ;
}

void NextLevel::run(Screen & screen_)
{
  while(this->getMenuState() == MenuState::NEXT)
  {
    this->draw(screen_);
  }
}

void NextLevel::draw(Screen & screen_){
  std::cout << " Cargando " << std::endl;
  screen_.display();
}
