#include "../include/player.h"

Player::Player() {}

Player::Player(Coord pos, std::string symbol, 
        int bulletCount,int lives , int speed, 
        int level_score, 
        int total_score):Personaje(pos, symbol, lives, speed)
{
    this->bulletCount = bulletCount;
    this->level_score = level_score;
    this->total_score = total_score;
};
void Player::printAttributes()
{
    Personaje::printAttributes();
    std::cout << "Bullet: " << bulletCount << std::endl;
}
