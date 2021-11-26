#include "../include/board.h"
#include <cstdlib>

Board::Board() {}

// implementar cols+2 rows+2
Board::Board(int _cols, int _rows, int _normalE) : cols{_cols}, rows{_rows}, numNormalE(_normalE){
  matrix = new int *[_rows + 2];

  for (int i = 0; i < _rows + 2; ++i)
    matrix[i] = new int[_cols + 2]{};
  enemyN = new NormalEnemy[numNormalE]; 
  this->player = Player({1, rows});
  generateMatrix();
  maze();
  initializeEnemies();
}

Board::~Board() {
  if (matrix != nullptr) {
    for (int i = 0; i < rows + 2; i++) {
      delete[] matrix[i];
    }
    delete[] matrix;
  }
  if(enemyN!=nullptr) delete [] enemyN;
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
  //find paredes, del punto seleccionado
  int FParedes = 8;
  int den = (rows+2) * (cols+2) / 4;
  srand(time(NULL));
  for (int i = 0; i < den; i++) {
    int x = rand() % ((cols+2) - 4) + 2;
    x = (x / 2) * 2; // tiene que ser par
    int y = rand() % ((rows+2) - 4) + 2;
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
        std::cout << RED << "/\\" << NC;
        // std::cout << RED << enemyN->getSymbol() << NC;
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

/* void Board::checkCollisionEnemy() {
    for (int i = 0; i < numNormalE; i++) {
        switch (matrix[enemyN[i].getOldPos().Y][enemyN[i].getOldPos().X]) {
        // case ENEMY: gameover = 1;  break;
        case WALL:
            player.setPos(player.getOldPos());
        default:
            break;
        }
    }
} */

void Board::initializeEnemies(){
    srand(time(NULL));
    int x, y;
    for (int i = 0; i < numNormalE; i++) {
        do{
            y = rand()% rows + 1;
            if (y < (rows / 3)) {
              x = rand() % cols + 1;
            } else {
              x = rand() % cols + (3 * cols / 4);
            }
        } while(matrix[y][x]!=0);
        enemyN[i].setPos({x, y});
    }
}

void Board::assignEnemyBox(){
    for (int i = 0; i < numNormalE; i++) {
        assignBox(enemyN[i].getPos(), ENEMY);
    }
}

void Board::update() {
  player.update();
  checkCollisionPlayer();
  assignBox(player.getOldPos(), EMPTY);
  assignBox(player.getPos(), PLAYER);
  assignEnemyBox();
  draw();
  //    assignBox( enemy.getPos(), 3);
  // halt( player.getPos());
}
