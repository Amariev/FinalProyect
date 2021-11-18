#include "../include/game.h"
#include "../include/player.h"
#include "../include/level.h"

#include <ctime>

Game::Game() 
{
    this->state = GameState::MENU;
    Level level;
}

Game::Game(int time_)
{
    this->time = time_;
}

Game::~Game(){}

GameState Game::getState()
{
    return state;
}

void Game::setState(GameState state_)
{
	this->state = state_;
}

void Game::clear_screen() 
{
    std::cout << "\033[2J\033[1;1H";
}

void Game::run() 
{
    level.load_level();
    Menu *const mainMenu = new MainMenu();
    auto menuState = mainMenu;
    while (state != END) {
        switch (this->state) 
        {
            case GameState::MENU: {
                clear_screen();
                while (menuState->getMenuState() != OUT)
                {
                    switch (menuState->getMenuState())
                    {
                        case MenuState::MAIN_MENU: {
                            menuState = mainMenu;
                            menuState->setMenuState(MenuState::MAIN_MENU);
                            menuState->run();
                        }

                        case MenuState::PLAY: {
                            this->state = GameState::RUN;
                            menuState->setMenuState(MenuState::OUT);
                            level.load_level();
                        }

                        default: {
                            break;
                        }
                    }
                }
                break;
            }
            case GameState::RUN: {
                clear_screen();
                level.draw();
                break;
            }

            default:{
                break;
            }
        }
    }
}
