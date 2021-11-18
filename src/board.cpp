#include "../include/board.h"

#define RED "\e[0;31m"

Board::Board(int columnas, int filas) : columnas{columnas}, filas{filas} {
  matriz = new int *[filas];
  for (int indice = 0; indice < filas; ++indice)
    matriz[indice] = new int[columnas]{};
}

// Métodos
void Board::inicializarMatriz() {
  // char matriz[filas][columnas];
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1) {
        matriz[i][j] = 1;
      } else {
        matriz[i][j] = 0;
      }
    }
  }
}

void Board::drawBoard() {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if (matriz[i][j] == 1) {
        /* char a = 178;
        std::cout << RED << a << a; */
        std::cout << RED "\u274E";
      }
      if (matriz[i][j] == 0) {
        std::cout << "  ";
      }
    }
    std::cout << "\n";
  }
}

