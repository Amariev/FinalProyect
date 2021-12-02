#include "../include/basic.h"

GameOver::GameOver()
{
  for (int i = 0; i < GAME_OVER_BUTTONS_QUANTITY; ++i)
  {
    Button * btn = new Button;

    switch(i)
    {
      case 0: btn->setName("Play Again"); break;
      case 1: btn->setName("Save"); break;
      case 2: btn->setName("Exit"); break;
      default: break;
    }

    this->buttons.push_back(btn);
  }
  this->buttons[this->buttonId]->setIcon("*");
  this->menuState = MenuState::MAIN_MENU;
}

GameOver::~GameOver()
{
  ;
}

void GameOver::run(Screen & screen_)
{
  while(this->getMenuState() == MenuState::GAME_OVER)
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
          this->moveDown(GAME_OVER_BUTTONS_QUANTITY);
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
              this->setMenuState(MenuState::SAVE);
              return;
            }
            case 2: 
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

void GameOver::draw(Screen & screen_)
{
  for (int i = 0; i < GAME_OVER_BUTTONS_QUANTITY; ++i)
	{
		this->buttons[i]->draw(screen_);
	}
}