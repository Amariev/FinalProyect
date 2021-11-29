#include "../include/level.h"
#include<thread>

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
    sleep(3);
    // delete board;
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

bool Level::draw() {
  // std::thread hilo1(&Level::change_level, this);
  // hilo1.join();
  // std::cout << "\033[2J\033[1;1H";
  return board->update();
}
