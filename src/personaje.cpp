#include "../include/player.h"

Player::Player(){}
Player::Player(Coord pos, std::string symbol, 
        int bulletCount,int lives , int speed, 
        int level_score, 
        int total_score):Personaje(pos, symbol, lives, speed)
{
    Player::bulletCount = bulletCount;
    Player::level_score = level_score;
    Player::total_score = total_score;
};
void Player::printAttributes()
{
    Personaje::printAttributes();
    std::cout << "Bullet: " << bulletCount << std::endl;
}
