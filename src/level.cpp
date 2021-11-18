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


/*

    Player *player1 = new Player(12, 14, '@');
    std::cout << "Ingresa tu nombre: ";
    std::cin >> player1->name;

   ******* Level *level = new Level(parametros)
*/
void Level::load_level() 
{
    this->number = 1;
    // load_player();
    Player player(2,2,'#');
    Enemy enemy(5,5,'t');

    this->board = Board(width, height, player, enemy);

    this->board.inicializarMatriz();

    int **matrix = board.getBoard();
    int row = board.rows;
    int col = board.cols;

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

void Level::draw()
{
    // std::cout << "\033[2J\033[1;1H";
    board.drawBoard();
}
