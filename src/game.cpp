#include "../include/game.h"
#include <iostream>

Game::Game()
{
    this->state = GameState::MENU;
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
    while (state != END) 
    {
        switch (this->state) 
        {
            case GameState::MENU:
                std::cout << "Bienvenido a aldkjfasldg" << std::endl;
            case GameState::RUN:
                
            default:
                break;
        }
    }
}
