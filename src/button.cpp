#include "../include/basic.h"

Button::Button()
{ 
  this->name = "DEFAULT";
}
Button::~Button()
{
  ;
}

void Button::draw(Screen & screen_)
{
  screen_.draw(this->getText());
}