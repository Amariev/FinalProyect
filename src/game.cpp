#include "../include/game.h"

Game::Game() 
{
    this->state = GameState::MENU;
    Level level;
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

void Game::clearScreen() 
{
    std::cout << "\033[2J\033[1;1H";
}

void Game::delay(int a)
{
    int add=0;
    int time;
    
    time = a * 10000000;

    for (int i = 0; i < time; i++)
    {
        add *= i;
        add++;
        add++;
    }
}

void Game::run() // 
{
    Menu *const mainMenu = new MainMenu();
    auto menuState = mainMenu;
    while (state != END) {
        delay(5);
        switch (this->state) {
            case GameState::MENU: {
                clearScreen();
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
                clearScreen();
                level.draw();
                break;
            }

            default:{
                break;
            }
        }
    }
}
