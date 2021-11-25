#include "../include/board.h"

Board::Board() {}

// implementar cols+2 rows+2
Board::Board(int _cols, int _rows) : cols{_cols}, rows{_rows} {
  matrix = new int *[_rows + 2];

  for (int i = 0; i < _rows + 2; ++i)
    matrix[i] = new int[_cols + 2]{};

  this->player = Player({1, rows - 1});
  generateMatrix();
  maze();
}

Board::~Board() {
  if (matrix != nullptr) {
    for (int i = 0; i < rows + 2; i++) {
      delete[] matrix[i];
    }
    delete[] matrix;
  }
}

// Métodos
void Board::generateMatrix() {
  for (int i = 0; i < rows + 2; i++) {
    for (int j = 0; j < cols + 2; j++) {
      if (i == 0 || j == 0 || i == (rows + 2) - 1 || j == (cols + 2) - 1) {
        matrix[i][j] = WALL;
      } else {
        matrix[i][j] = EMPTY;
      }
    }
  }
}

void Board::maze() {
  int FParedes = 8;
  int den = rows * cols / 4;
  srand(time(NULL));
  for (int i = 0; i < den; i++) {
    int x = rand() % (cols - 4) + 2;
    x = (x / 2) * 2; // tiene que ser par
    int y = rand() % (rows - 4) + 2;
    y = (y / 2) * 2;
    matrix[y][x] = WALL;
    for (int j = 0; j < FParedes; j++) { // crear matrices para las paredes
      int mx[4] = {x, x, x + 2, x - 2};
      int my[4] = {y + 2, y - 2, y, y};
      int r = rand() % 4; // 0-3, escoger un indice de la matriz

      if (matrix[my[r]][mx[r]] == EMPTY) {
        matrix[my[r]][mx[r]] = WALL;
        matrix[my[r] + (y - my[r]) / 2][mx[r] + (x - mx[r]) / 2] = WALL;
      }
    }
  }
}

void Board::draw() {
  for (int i = 0; i < rows + 2; i++) {
    for (int j = 0; j < cols + 2; j++) {
      switch (matrix[i][j]) {
      case WALL:
        //   std::cout << "\u274E";
        std::cout << ":3";
        break;
      case PLAYER:
        std::cout << BLUE << player.getSymbol() << NC;
        break;
      case ENEMY:
        std::cout << RED << enemy.getSymbol() << NC;
        break;
      default:
        std::cout << "  ";
        break;
      }
    }
    std::cout << "\n";
  }
}

void Board::assignBox(Coord pos, material mat) {
  for (int i = 1; i < (rows + 2) - 1; i++) {
    for (int j = 1; j < (cols + 2) - 1; j++) {
      if (i == pos.Y && j == pos.X) {
        matrix[i][j] = mat;
      }
    }
  }
}

void Board::checkCollisionPlayer() {
    switch (matrix[player.getPos().Y][player.getPos().X]) {
    // case ENEMY: gameover = 1;  break;
    case WALL:
        player.setPos(player.getOldPos());
    default:
        break;
  }
}

void Board::update() {
  player.update();
  checkCollisionPlayer();
  assignBox(player.getOldPos(), EMPTY);
  assignBox(player.getPos(), PLAYER);
  draw();
  //    assignBox( enemy.getPos(), 3);
  // halt( player.getPos());
}
