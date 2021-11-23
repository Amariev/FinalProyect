#include "../include/level.h"

Level::Level(){
}

Level::Level(int _number) 
{
    this->number = _number;
}

Level::~Level(){
    if(board!=nullptr){delete board;}
}

void Level::load_level() 
{
    this->number = 1;
    Enemy enemy({5,5},"\u2620");

    this->board = new Board;

    this->board->generateMatrix();

    int **matrix = board->getBoard();
    int row = board->rows;
    int col = board->cols;
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


void Level::draw()
{
    // std::cout << "\033[2J\033[1;1H";
    board->drawBoard();
}
