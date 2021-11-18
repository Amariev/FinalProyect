#include "../include/board.h"


Board::Board(int columnas, int filas, Player _player, Enemy _enemy) : cols{columnas}, rows{filas} {
  matrix = new int *[filas];
  for (int index = 0; index < filas; ++index)
    matrix[index] = new int[columnas]{};
  
  this -> player = _player;
  this -> enemy = _enemy;
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

Board::~Board() {
    for (int i= 0 ; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Board::drawBoard() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 1) {
        char a = 178;
        std::cout << RED << a << a;
        // std::cout << RED "\u274E" ;
      }
      if (matrix[i][j] == 0) {
        std::cout << "  ";
      }
    }
    std::cout << "\n";
  }
}

