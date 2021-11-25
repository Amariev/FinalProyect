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

void Player::input(){
    if (kbhit()) {
        switch (getch()) {
            case 'w': case 'W': case 'i': case 'I':
                direction = UP;
                break;
            case 's': case 'S': case 'k': case 'K':
                direction = DOWN;
                break;
            case 'a': case 'A': case 'j': case 'J':
                direction = LEFT;
                break;
            case 'd': case 'D': case 'l': case 'L':
                direction = RIGHT;
                break;
        }
    }
    move();
    direction = STOP;
}

void Player::printAttributes()
{
    Personaje::printAttributes();
    std::cout << "Bullet: " << bulletCount << std::endl;
}

void Player::update(){
    input();
}
