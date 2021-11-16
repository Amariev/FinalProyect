#include "../include/board.h"
#include "../include/enemy.h"

#define RED "\e[0;31m"

Board::Board(int columnas, int filas) : cols{columnas}, rows{filas} {
  matrix = new int *[filas];
  for (int index = 0; index < filas; ++index)
    matrix[index] = new int[columnas]{};
}

// Métodos
void Board::inicializarMatriz() {
  // char matriz[filas][columnas];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
        matrix[i][j] = 1;
      } else {
        matrix[i][j] = 0;
      }
    }
  }
}

void Board::drawBoard() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 1) {
        char a = 178;
        std::cout << RED << a << a;
        // std::cout << RED "\u2588" << "\u2588";
      }
      if (matrix[i][j] == 0) {
        std::cout << "  ";
      }
    }
    std::cout << "\n";
  }
}

