#include "../include/board.h"

Board::Board(){}

// implementar cols+2 rows+2
Board::Board(int _cols, int _rows) : cols{_cols}, rows{_rows} {
    matrix = new int *[_rows+2];

    for (int i = 0; i < _rows+2; ++i)
        matrix[i] = new int[_cols+2]{};
        
    // maze.laberinto(rows+2, cols+2, matrix);
    generateMatrix();
}

Board::~Board() {
    // if(matrix!=nullptr){
    //    for (int i= 0 ; i < rows; i++)
    //    {
    //      delete[] matrix[i];
    //    }
    //   delete[] matrix; 
    // }
}

// Métodos
void Board::generateMatrix() {
  for (int i = 0; i < rows+2; i++) {
    for (int j = 0; j < cols+2; j++) {
      if (i == 0 || j == 0 || i == (rows+2) - 1 || j == (cols+2) - 1) {
        matrix[i][j] = 1;
      } else {
        matrix[i][j] = 0;
      }
    }
  }
}

// void Board::assignBox(Coord pos, int value){
//   for (int i = 1; i < (rows + 2) - 1; i++){
//     for (int j = 1 ; j < (cols + 2) - 1; j++){
//       if( i == pos. && j == pos.Y){
//         matrix[i][j]= value;
//       }
//     }
//   }
// }

// switch

void Board::drawBoard(){
  for (int i = 0 ; i < rows + 2; i ++){
    for(int j = 0; j < cols + 2; j++){
      switch (matrix[i][j]) {
        case 1:
          std::cout << "\u274E";
          break;
        case 2:
          std::cout << BLUE << player.getSymbol() << NC;
          break;
        case 3:
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

// void for (i){for(j){if(matrix[i][j] == 1 && player.pos.x == i && player.pos.y == j){ entonces direction = STOP}}

//PROBAR


// void Board::halt(Coord pos){
//   for (int i = 0; i < rows +2; i++){
//     for (int j = 0; j < cols+ 2; j++){
//       if (matrix[i][j] == 1 && i == pos.X && j == pos.Y) {
//         player.setDirection(STOP);
//       }
//     }
//   }
// }

void Board::update(){
//   assignBox( player.getPos(), 2);
//   assignBox( enemy.getPos(), 3);
  //halt( player.getPos());
}
