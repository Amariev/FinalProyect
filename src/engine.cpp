#include "../include/basic.h"

Engine::Engine(Screen & screen_)
{
  this->totalLevels = LEVELS_QUANTITY;
  this->currentLevel = STARTING_LEVEL_NUMBER;
  this->running = false;

  this->player = new Player();

  Level *const level1 = new Level(screen_, this->player);
  this->levels.push_back(level1);
  Level *const level2 = new Level(screen_, this->player);
  this->levels.push_back(level2);

  for (Level * const level : this->levels)
	{
		level->resetPoints();
		level->resetTime();
	}
}

Engine::~Engine()
{
  ;
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
  NextLevel *const next = new NextLevel(this->currentLevel);
  next->draw(screen_);
  usleep(3000);

  delete next;

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

  this->totalStats.pts = level_->getPoints();
  this->totalStats.tm = level_->getTime();

  return shouldContinue;
}