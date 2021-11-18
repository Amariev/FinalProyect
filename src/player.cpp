#include "../include/player.h"

Player::Player(){}
Player::Player(int row, int col, std::string symbol, 
        int bulletCount,int lives , int speed, 
        int level_score, 
        int total_score):Personaje(row, col, symbol, lives, speed)
{
    Player::bulletCount = bulletCount;
    Player::level_score = level_score;
    Player::total_score = total_score;
};
void Player::imprimirAtributos()
{
    std::cout << "Row: " << row << std::endl;
    std::cout << "Col: "<< col << std::endl;
    std::cout << "Symbol: "<< symbol << std::endl;
    std::cout << "Lives: "<< lives << std::endl;
    std::cout << "Speed: "<< speed << std::endl;
    std::cout << "Bullet: " << bulletCount << std::endl;
}
