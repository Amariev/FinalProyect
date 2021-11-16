#include "../include/game.h"
#include "../include/player.h"
#include <ctime>

Game::Game() 
{
    this->state = GameState::RUN;
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
    Board *board = new Board(29, 19);
    board->inicializarMatriz();
    int **matrix = board->getBoard();
    int row = board->filas;
    int col = board->columnas;
    Maze *maze = new Maze(matrix, row, col);
    maze->laberinto();
    Player *player1 = new Player(12, 14, '@');
    std::cout << "Ingresa tu nombre: ";
    std::cin >> player1->name;
    while (state != END) {
        std::cout << this->state << std::endl;
        switch (this->state) 
        {
            case GameState::MENU: {
                clear_screen();
                std::cout << "Bienvenido a aldkjfasldg" << std::endl;
                break;
            }
            case GameState::RUN: {
                clear_screen();
                std::cout << "Bienvenido al juego " << player1->name << std::endl;
                board->drawBoard();
                player1->imprimirAtributos();
                break;
            }

            default:{
                break;
            }
        }
    }
}
