#include <iostream>
#include "include/personaje.h"
#include "include/player.h"
#include "include/enemy.h"
#include "include/maze.h"

using namespace std;

void dibujarLaberinto();
int main(){
    dibujarLaberinto();

    cout << "Bienvenidos al programa de testing" << endl;
    cout << "Probando clase Personaje" << endl;
    Personaje pedrito(3, 4, '@');
    Personaje enemigo1(2, 3, 'e');

    cout << "antes de funciones set y get : " << endl;
    pedrito.imprimirAtributos();
    enemigo1.imprimirAtributos();

    pedrito.setLives(1);
    enemigo1.setLives(3);
    pedrito.setSpeed(2);
    enemigo1.setSpeed(1);

    cout << "despues de funciones: " << endl;
    pedrito.imprimirAtributos();
    enemigo1.imprimirAtributos();

    cout << "Creacion Player..." << endl;
    Player player1(4, 34, '&');
    cout << "Ingrese su nombre: " << endl;
    cin >> player1.name;
    cout << "Hola " << player1.name << " estos son tus atributos" << endl;
    player1.imprimirAtributos();

    cout << "Creacion Enemigo..." << endl;
    Enemy enemigo2(4, 34, '#');
    enemigo2.setLives(3);
    enemigo2.imprimirAtributos();
    
    return 0;
}

void dibujarLaberinto() 
{
    srand(time(NULL));
    Maze laberinto1(29, 19);
    laberinto1.inicializarMatriz();
    laberinto1.laberinto();
    laberinto1.drawMaze();
}
