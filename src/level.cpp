#include "../include/basic.h"

Level::Level(Screen & screen_, Player *& player_) :
  screen(screen_), player(player_), interface(player_)
{
  ;
}

Level::~Level()
{
  ;
}

void Level::generate(Screen & screen_)
{
  int rows = screen_.getHeight();
  int cols = screen_.getWidth();

  for (int i = 0; i < rows + 2; i++) {
    for (int j = 0; j < cols + 2; j++) {
      if (i == 0 || j == 0 || i == (rows + 2) - 1 || j == (cols + 2) - 1) {
        screen_.getSelf()[i][j] = TileType::STONE;
      } else {
        screen_.getSelf()[i][j] = TileType::BLANK;
      }
    }
  }
}

bool Level::play(Screen & screen_, Player *& player_)
{
  this->generate(screen_);

  std::cout << "playing" << std::endl;
  // this->player = 
}