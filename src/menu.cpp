#include "../include/basic.h"

Menu::Menu()
{
  this->buttonId = 0;
}

Menu::~Menu()
{
  ;
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