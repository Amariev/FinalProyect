#include <iostream>
#include "../include/maze.h"

const int filas = 29; //impar
const int columnas = 19; //impar
const int densidad = 1; // 0 - 1
char matriz [filas][columnas];

const int FParedes = densidad *4;

int den = filas * columnas * densidad/4;

using namespace std; 

//NUEVO
void Maze::inicializarMatriz()
{    
	for (int i = 0; i < filas; i++)
     {
		for (int j = 0; j < columnas; j++) 
        {
			if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1) 
            {
				matriz[i][j] = 1;
			}
			else 
            {
				matriz[i][j] = 0; 
			}
		}
	}
}
void Maze::laberinto ()
{
	for (int i = 0; i < den; i++) {
		int x = rand() % (columnas - 4) + 2; // 2 18 
		x = (x / 2) * 2;  // tiene que ser par 
		int y = rand()% (filas - 4) + 2;
		y = (y / 2) * 2;
		matriz[y][x] = 1; 
		for (int j = 0; j < FParedes; j++) 
        {   //crear matrices para las paredes
			int mx[4] = { x,  x,  x + 2, x - 2 }; 
			int my[4] = { y + 2,y - 2, y ,  y };
			int r = rand() % 4; //0-3, escoger un indice de la matriz

			if (matriz[my[r]][mx[r]] == 0) 
            {
				matriz[my[r]][mx[r]] = 1; 
				matriz[my[r] +( y - my[r])/2][mx[r]+(x- mx[r])/2] = 1;
			}				
		}
	}
}

void Maze::drawMaze()
{   //laberinto();
    for (int i = 0; i < filas; i++)
     {
		for (int j = 0; j < columnas; j++)
         {
			if (matriz[i][j] == 1) 
            {
				char a= 178; 
				cout << a <<a; 
			}
			if(matriz[i][j] == 0)
            {
				cout << "  ";
			}
		}
		cout << "\n"; 
	}
}
