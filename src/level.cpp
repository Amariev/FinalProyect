#include "../include/basic.h"

Level::Level(Screen & screen_, Player *& player_) :
  screen(screen_), player(player_), interface(player_)
{
  this->isActive = true;
	this->isCompleted = false;
  this->startX = 5;
	this->startY = 5;
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

  int FParedes = 8;
  int den = (rows+2) * (cols+2) / 4;
  for (int i = 0; i < den; i++) {
    int x = rand() % ((cols+2) - 4) + 2;
    x = (x / 2) * 2; // tiene que ser par
    int y = rand() % ((rows+2) - 4) + 2;
    y = (y / 2) * 2;
    screen_.getSelf()[y][x] = TileType::STONE;
    for (int j = 0; j < FParedes; j++) { // crear matrices para las paredes
      int mx[4] = {x, x, x + 2, x - 2};
      int my[4] = {y + 2, y - 2, y, y};
      int r = rand() % 4; // 0-3, escoger un indice de la matriz

      if (screen_.getSelf()[my[r]][mx[r]] == TileType::BLANK) {
        screen_.getSelf()[my[r]][mx[r]] = TileType::STONE;
        screen_.getSelf()[my[r] + (y - my[r]) / 2][mx[r] + (x - mx[r]) / 2] = TileType::STONE;
      }
    }
  }


  for (int i = 0; i < rows + 2; i++) {
    for (int j = 0; j < cols + 2; j++) {
      TileType type = TileType(screen_.getSelf()[i][j]);
      Tile * tile = new Tile;
      tile = tile->getTilePointer(type);
      tile->setCoords({ i, j });
      this->tiles.push_back(tile);
    }
  }
}

void Level::checkCollisions()
{
  ;
}

void Level::update()
{
  ;
}

void Level::draw()
{
  for (std::vector<Tile *>::iterator it = this->tiles.begin(); it != this->tiles.end(); ++it)
  {
    if (*it == nullptr) continue;

    this->screen.draw((*it));
  }
  this->screen.display();
}

bool Level::play(Screen & screen_, Player *& player_)
{
  this->generate(screen_);
  
  std::cout << "aaaaaa" << std::endl;

  // while(this->isActive)
  // {
  //   // this->checkCollisions();
  //   // this->update();
  //   // this->draw();
  //   ;
  // }

  return this->isCompleted;
}