#include "../include/maze.h"

Maze::Maze() {
    FParedes = 8;
}
void Maze::laberinto(int _rows, int _cols, int **matrix) {
    int den = _rows * _cols /4;
    srand(time(NULL));
    for (int i = 0; i < den; i++) {
		int x = rand() % (_cols - 4) + 2; // 2 18
                x = (x / 2) * 2;                // tiene que ser par 
		int y = rand()% (_rows - 4) + 2;
		y = (y / 2) * 2;
		matrix[y][x] = 1; 
		for (int j = 0; j < FParedes; j++) 
        {   //crear matrices para las paredes
			int mx[4] = { x,  x,  x + 2, x - 2 }; 
			int my[4] = { y + 2,y - 2, y ,  y };
			int r = rand() % 4; //0-3, escoger un indice de la matriz

			if (matrix[my[r]][mx[r]] == 0) 
            {
				matrix[my[r]][mx[r]] = 1; 
				matrix[my[r] +( y - my[r])/2][mx[r]+(x- mx[r])/2] = 1;
			}				
		}
	}
}
