#include "../include/basic.h"

Game::Game(Screen & screen_) : screen (screen_)
{
  this->lastPoints = 0.f;
  this->lastTime = 0.f;
}

Game::~Game() 
{
  ;
}

void Game::run() 
{
  Menu *const mainMenu = new MainMenu();
  auto menuState = mainMenu; 

  while(state != END)
  {
    switch (this->state)
    {
      case GameState::MENU: {
        while (menuState->getMenuState() != OUT){
          switch (menuState->getMenuState())
          {
            case MenuState::MAIN_MENU: {
              menuState = mainMenu;
              menuState->setMenuState(MenuState::MAIN_MENU);
              menuState->run(this->screen);
              break;
            }
            case MenuState::PLAY: {
              this->state = GameState::GAME;
              menuState->setMenuState(MenuState::OUT);
              break;
            }
            case MenuState::EXIT: {
              menuState->setMenuState(MenuState::OUT);
              this->state = GameState::END;
              break;
            }
            default: {
              break;
            }
          }
        }
        break;
      }
      case GameState::GAME: {
        Engine *engine = new Engine(this->screen);
        engine->run(this->screen);
        this->updateScore(engine->getPoints(), engine->getTime());
        this->state = GameState::MENU;
        menuState->setMenuState(MenuState::GAME_OVER);
        delete engine;
        
        break;
      }
      case GameState::END: {
        break;
      }
      default: {
        break;
      }
    }
  }
}

void Game::updateScore(int points_, float time_){
  this->lastPoints = points_;
  this->lastTime = time_;
}