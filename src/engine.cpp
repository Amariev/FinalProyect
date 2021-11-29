#include "../include/basic.h"

Engine::Engine(Screen & screen_)
{
  this->totalLevels = LEVELS_QUANTITY;
  this->currentLevel = STARTING_LEVEL_NUMBER;
  this->running = false;

  this->player = new Player(5);

  Level *const level1 = new Level(screen_, this->player, 8);
  this->levels.push_back(level1);

  for (Level * const level : this->levels)
	{
    level->setLevelName("");
    level->setLevelNumber(1);
	}
}

Engine::~Engine() 
{
  for (auto l : levels) {
    if (l != nullptr) {
      delete l;
    }
  }
  levels.clear();

  if(player!=nullptr){
    delete player;
  }
}
 
void Engine::run(Screen & screen_)
{
  this->running = true;
  for (Level *const level: this->levels)
  {
    if (!this->play(screen_, level))
    {
      break;
    }
  }

  this->running = false;
}
bool Engine::play(Screen & screen_, Level * level_){
  bool shouldContinue = false;

  if (level_->play(screen_, this->player))
  {
    this->currentLevel++;
    shouldContinue = true;
  }
  else
  {
    shouldContinue = false;
  }

  return shouldContinue;
}
