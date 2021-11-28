#include "../include/level.h"

Level::Level() {
  width = 25;
  height = 25;
  this->board = new Board(width, height, 8);
}

Level::~Level() {
  if (board != nullptr) {
    delete board;
  }
}

/* void Level::load_level() {
  board->generateMatrix();
} */

// cambio de nivel
void Level::change_level() {
  delete board;
  width += 2;
  height += 2;
  this->board = new Board(width, height, 3);
}

// comprobar el nivel
void Level::check_end_level() {}

void Level::reset_game() {}

// bool Level::ended(){
//   if(end) return 1;
//   else return 0;
// }

void Level::draw() {
      std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
  // std::cout << "\033[2J\033[1;1H";
  board->update();
}
