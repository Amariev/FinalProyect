#include "../include/level.h"

Level::Level(){
}

Level::Level(int _number) 
{
    this->number = _number;
    load_level();

}

Level::~Level(){
    // if(board!=nullptr){delete board;}
}

void Level::load_level() 
{
    this->number = 1;
    this->board = Board(5, 5);
    board.generateMatrix();
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
    board.drawBoard();
}
