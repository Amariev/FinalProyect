#include "../include/basic.h"

Menu::Menu()
{
  this->buttonId = 0;
}

Menu::~Menu()
{
  for(auto b : buttons){
    if(b!=nullptr) delete b;
  }
  buttons.clear();
}

void Menu::moveUp()
{
	if (this->buttonId - 1 >= 0)
	{
    this->buttons[this->buttonId]->setIcon(" ");
		this->buttonId--;
    this->buttons[this->buttonId]->setIcon("*");
	}
}

void Menu::moveDown(int maxNumber_)
{
	if (this->buttonId + 1 < maxNumber_)
	{
		this->buttons[this->buttonId]->setIcon(" ");
		this->buttonId++;
    this->buttons[this->buttonId]->setIcon("*");
	}
}

void Menu::draw(Screen &screen_)
{
  std::string mark1 = "\u2550";
  std::string mark2 = "\u2554";
  std::string mark3 = "\u2557";
  std::string topLine = "";
  for(int i=0;i<11;i++)
  {
        if(i==0)  topLine += mark2;
        else if(i==10) topLine += mark3;
        else topLine += mark1;
  }
  mark1 = "\u2550";
  mark2 = "\u255A";
  mark3 = "\u255D";
  std::string bottonLine = "";
  for (int i = 0; i < 11; i++) {
        if(i==0) bottonLine += mark2;
        else if(i==10) bottonLine += mark3;
        else bottonLine += mark1;
  }
  screen_.draw(topLine);
  screen_.draw("|  MENU   |");
  screen_.draw(bottonLine);
}
