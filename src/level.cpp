#include "../include/level.h"
#include "../include/maze.h"
#include "../include/player.h"

Level::Level(int number, int width, int height) 
{
    this->number = number;
    this->width = width;
    this->height = height;
}

void Level::load_level() 
{
    Maze laberinto(width, height);
    Player jugador(height - 1, 1, '@');

}

void Level::change_level()
{
    
}

void Level::check_end_level()
{
    
}
