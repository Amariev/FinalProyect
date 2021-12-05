#include "../include/basic.h"
#include <string>

Engine::Engine(Screen &screen_) {
  this->currentLevel = STARTING_LEVEL_NUMBER;
  this->running = false;

  this->player = new Player(5);
  this->player->setPosition({ 1, screen_.getHeight() });
  Level *const level1 = new Level(this->player, 5);
  Level *const level2 = new Level(this->player, 6);
  Level *const level3 = new Level(this->player, 7);
  Level *const level4 = new Level(this->player, 8);
  Level *const level5 = new Level(this->player, 9);
  Level *const level6 = new Level(this->player, 9);
  Level *const level7 = new Level(this->player, 10);
  this->levels.push_back(level1);
  this->levels.push_back(level2);
  this->levels.push_back(level3);
  this->levels.push_back(level4);
  this->levels.push_back(level5);
  this->levels.push_back(level6);
  this->levels.push_back(level7);

  int cont = 1;
  for (Level *const level : this->levels) {
    std::string str = std::to_string(cont);
    level->setLevelName("Level " + str);
    level->setLevelNumber(cont);
    cont++;
  }
}

Engine::~Engine() {
  for (auto l : levels) {
    if (l != nullptr)
      delete l;
  }
  levels.clear();

  if (player != nullptr)
    delete player;
}

void Engine::run(Screen &screen_) {
  this->running = true;
  for (Level *const level : this->levels) {
    if (!this->play(screen_, level)) {
      break;
    }
    level->nextLevel(screen_);
  }
  this->running = false;
}

bool Engine::play(Screen &screen_, Level *level_) {
  bool shouldContinue = false;

  if (level_->play(screen_, this->player)) {
    this->currentLevel++;
    shouldContinue = true;
  } else {
    shouldContinue = false;
  }

  return shouldContinue;
}
