#include "../include/basic.h"

Screen::Screen() { ; }

Screen::~Screen() 
{ 
  for(int i=0; i<height; i++){
    delete self[i];
  }
  delete[] self;
  height = 0;
  width = 0;
}

void Screen::create(int width_, int height_)
{
  this->height = height_;
  this->width = width_;
  this->self = new int *[height_ + 2];

  for (int i = 0; i < height_ + 2; ++i)
    this->self[i] = new int[width_ + 2]{};
}

void Screen::generateMap()
{
  int rows = height;
  int cols = width;

  for (int i = 0; i < rows + 2; i++) {
    for (int j = 0; j < cols + 2; j++) {
      if (i == 0 || j == 0 || i == (rows + 2) - 1 || j == (cols + 2) - 1) {
        self[i][j] = TileType::STONE;
      } else {
        self[i][j] = TileType::BLANK;
      }
    }
  }

  int FParedes = 8;
  int den = (rows+2) * (cols+2) / 4;
  for (int i = 0; i < den; i++) {
    int x = rand() % ((cols+2) - 4) + 2;
    x = (x / 2) * 2;
    int y = rand() % ((rows+2) - 4) + 2;
    y = (y / 2) * 2;
    self[y][x] = TileType::STONE;
    for (int j = 0; j < FParedes; j++) {
      int mx[4] = {x, x, x + 2, x - 2};
      int my[4] = {y + 2, y - 2, y, y};
      int r = rand() % 4;

      if (self[my[r]][mx[r]] == TileType::BLANK) {
        self[my[r]][mx[r]] = TileType::STONE;
        self[my[r] + (y - my[r]) / 2][mx[r] + (x - mx[r]) / 2] = TileType::STONE;
      }
    }
  }
}

void Screen::assignEntity(Coord cords_, TileType tile_)
{
  this->self[cords_.Y][cords_.X] = tile_;
}

void Screen::assignEntity(Coord oldCoord_, Coord cords_, TileType tile_)
{
  this->self[oldCoord_.Y][oldCoord_.X] = TileType::BLANK;
  this->self[cords_.Y][cords_.X] = tile_;
}

void Screen::draw(std::string value_)
{
  std::cout << value_ << std::endl;
}

void Screen::draw()
{
  int rows = height;
  int cols = width;

  for (int i = 0; i < rows + 2; i++) {
    std::cout << "\t";
    for (int j = 0; j < cols + 2; j++) {
      switch (self[i][j]) {
      case TileType::STONE:
        std::cout << ":3";
        break;
      case TileType::PLAYER:
        std::cout << BLUE << "<>" << NC;
        break;
      case TileType::ENEMY:
        std::cout << RED << "/\\" << NC;
        break;
      case TileType::BOMB:
        std::cout << RED << "\U0001f4a3" << NC;
        break;
      default:
        std::cout << "  ";
        break;
      }
    }
    std::cout << "\n";
  }
}

void Screen::display()
{
  usleep(70 * 1000);
  std::cout << "\033[2J\033[1;1H";
}
