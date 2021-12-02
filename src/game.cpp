#include "../include/basic.h"

Game::Game(Screen & screen_) : screen (screen_)
{
  std::string databaseName = Resources::databasePath("register.txt");
  this->registerDb = new Database<Register>(databaseName, 2);
  this->registerDb->read();
  this->screen.create(25, 25);
}

Game::~Game() 
{
  if(registerDb!=nullptr) delete registerDb;
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
              menuState = new MainMenu();
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

        this->state = GameState::GAMEOVER;
        
        menuState = new GameOver();
        menuState->setMenuState(MenuState::GAME_OVER);
        delete engine;
        
        break;
      }
      case GameState::GAMEOVER: {
        bool flag = true;
        while (menuState->getMenuState() != OUT && flag) {
          menuState->run(this->screen);
          switch (menuState->getMenuState())
          {
            case MenuState::PLAY: {
              this->state = GameState::GAME;
              menuState->setMenuState(MenuState::OUT);
              break;
            }
            case MenuState::SAVE: {
              this->save();
              this->state = GameState::MENU;
              menuState->setMenuState(MenuState::MAIN_MENU);
              flag = false;
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
      default: break;
    }
  }
}


void Game::save()
{
  std::string guid = Resources::getUUID();

  Register *reg = new Register(guid, "99999");
  this->registerDb->add(reg);
  this->registerDb->write();
}
