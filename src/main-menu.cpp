#include "../include/basic.h"

MainMenu::MainMenu()
{
  for (int i = 0; i < MAIN_MENU_BUTTONS_QUANTITY; ++i)
  {
    Button * btn = new Button;

    switch(i)
    {
      case 0: btn->setName("Play"); break;
      case 1: btn->setName("Exit"); break;
      default: break;
    }

    this->buttons.push_back(btn);
  }
  this->buttons[this->buttonId]->setIcon("*");
  this->menuState = MenuState::MAIN_MENU;
}

MainMenu::~MainMenu()
{
  ;
}

void MainMenu::run(Screen & screen_)
{
  while(this->getMenuState() == MenuState::MAIN_MENU)
  {
    if (kbhit()) 
    {
      switch (getch()) 
      {
        case 'w': 
        case 'W':
          this->moveUp();
          break;
        case 's': 
        case 'S':
          this->moveDown(MAIN_MENU_BUTTONS_QUANTITY);
          break;
        case 10:
          switch (this->getButtonId())
          {
            case 0: 
            { 
              this->setMenuState(MenuState::PLAY); 
              return; 
            }
            case 1: 
              { 
                this->setMenuState(MenuState::EXIT);
                return; 
              }
            default: break;
          }
        break;
      	default: break;
      }
    }

    this->draw(screen_);
    screen_.display();
  }
}

void MainMenu::draw(Screen &screen_) 
{
  Menu::draw(screen_);
  for (int i = 0; i < MAIN_MENU_BUTTONS_QUANTITY; ++i)
	{
		this->buttons[i]->draw(screen_);
	}
}
