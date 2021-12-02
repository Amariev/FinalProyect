#include "../include/basic.h"

int main()
{
  Screen screen;
  Game *const game = new Game(screen);
  game->run();

  delete game;

  return 0;
}
