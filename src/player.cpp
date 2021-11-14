#include "../include/player.h"

Player::Player(int row, int col, char symbol, 
        int bulletCount,int lives , int speed, 
        int level_score, 
        int total_score):Personaje(row, col, symbol, lives, speed)
{
    Player::bulletCount = bulletCount;
    Player::level_score = level_score;
    Player::total_score = total_score;
};
