#include "../include/basic.h"

Level::Level(Screen & screen_, Player *& player_, int numberEnemies_) :
  screen(screen_), player(player_), interface(player_)
{
	this->isCompleted = false;
  this->numberEnemies = numberEnemies_;
  this->enemies = new Normal[this->numberEnemies];

  this->player->setPosition({ 1, screen_.getHeight() });
}

Level::~Level() 
{
if(enemies!=nullptr) delete [] enemies;
}

void Level::generateEnemy(Screen & screen_)
{
  int rows = screen_.getHeight();
  int cols = screen_.getWidth();

  // srand(time(NULL));
  int x, y;
  for (int i = 0; i < this->numberEnemies; i++) {
    do{
      y = rand()% rows + 1;
            /* if (y < (rows / 3)) {
              x = rand() % cols + 1;
            } else {
              x = rand() % cols + (3 * cols / 4);
            } */
            x = rand() % cols + 1;
    } while(screen_.getSelf()[y][x]!=0);
    enemies[i].setPosition({x, y});
    enemies[i].setRandomDirection();
  }
}

void Level::checkCollisions(Screen & screen_)
{
  Coord position = player->getPosition();
  switch(screen_.getSelf()[position.Y][position.X])
  {
    case TileType::ENEMY:
      this->isCompleted = true;
      break;
    case TileType::STONE:
      player->setPosition(player->getLastPosition());
      break;
    default:
      break;
  }

  for (int i = 0; i < numberEnemies; i++) {
    Coord enemyPosition = enemies[i].getPosition();
    switch (screen_.getSelf()[enemyPosition.Y][enemyPosition.X]) {
      case TileType::STONE:
        enemies[i].setPosition(enemies[i].getLastPosition());
        enemies[i].setRandomDirection();
        break;
      default: break;
      }
  }
  
  for (int i = 0; i < this->player->getTotalBombs(); i++) {
    auto bomb = this->player->getBombs()[i];
    Coord bombPosition = bomb.getPosition();
    switch (screen_.getSelf()[bombPosition.Y][bombPosition.X]) {
      case TileType::ENEMY:
        bomb.setActive(false);
        screen_.assignEntity(bombPosition, TileType::BLANK);
        screen_.assignEntity(enemies[i].getPosition(), TileType::BLANK);
        break;
      default: break;
      }
  }
}

void Level::update(Screen & screen_)
{
  for (int i = 0; i < this->player->getTotalBombs(); i++) {
    auto bomb = this->player->getBombs()[i];
    if (bomb.isActive()) 
    {
      this->player->getBombs()[i].tickTime();
      screen_.assignEntity(bomb.getPosition(), TileType::BOMB);
    }
    else
    {
      screen_.assignEntity(bomb.getPosition(), TileType::BLANK);
    }
  }

  if (this->player->isAbilityCast())
  {
    this->player->setBombPosition();
    this->player->setAbilityCast(false);
  }

   for (int i = 0; i < numberEnemies; i++) {
    enemies[i].update();
   }

  this->player->update();
}

void Level::draw(Screen &screen_) {
  std::cout << "\t" << levelName << std::endl;
  screen_.draw();
  int rows = screen_.getHeight();
  int cols = screen_.getWidth();

  screen_.assignEntity(player->getLastPosition(), player->getPosition(),
                       TileType::PLAYER);

  for (int i = 0; i < numberEnemies; i++) {
    Coord position = enemies[i].getPosition();

    if (position.X >= 1 && position.X <= cols && position.Y >= 1 && position.Y <= rows) {
      screen_.assignEntity(enemies[i].getLastPosition(), enemies[i].getPosition(), TileType::ENEMY);
    }
  }
  
  this->screen.display();
}

bool Level::play(Screen & screen_, Player *& player_)
{
  screen_.generateMap();
  this->generateEnemy(screen_);

  while (!this->isCompleted) {
    screen_.generateTime();
    this->update(screen_);
    this->checkCollisions(screen_);
    this->draw(screen_);
  }

  return this->isCompleted;
}
