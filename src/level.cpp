#include "../include/level.h"

Level::Level(){
    this->width = 25;
    this->height = 15;
}

Level::Level(int number, int width, int height) 
{
    this->number = number;
    this->width = width;
    this->height = height;
}

Level::~Level() {
    /* if (board != nullptr)
        delete board;
    if(player != nullptr)
        delete player; */
}

void Level::load_level() 
{
    this->number = 1;
    load_player();
    Enemy enemy(5,5,"\u2620");

    this->board = new Board(width, height, player, enemy);

    this->board->inicializarMatriz();

    int **matrix = board->getBoard();
    int row = board->rows;
    int col = board->cols;

    Maze *maze = new Maze(matrix, row, col);
    maze->laberinto();
}


//cambio de nivel
void Level::change_level()
{
    //switch case
}

//comprobar el nivel
void Level::check_end_level()
{
    
} 

void Level::load_player()
{
    // player->setRow((this->height)-1);
    // player->setCol(1);
    player = new Player(this->height, 1, "\u2689");

}

void Level::draw()
{
    // std::cout << "\033[2J\033[1;1H";
    board->drawBoard();
    player->imprimirAtributos(); 
}
