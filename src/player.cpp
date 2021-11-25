#include "../include/player.h"

Player::Player() {}

Player::Player(Coord pos, std::string symbol, int lives, 
        int levelScore, int totalScore):Personaje(pos, symbol, lives)
{
    this->levelScore = levelScore;
    this->totalScore = totalScore;
    this->direction = STOP;
};

void Player::input(){
    if (kbhit()) {
        switch (getch()) {
            case 'w': case 'W':
                direction = UP;
                break;
            case 's': case 'S':
                direction = DOWN;
                break;
            case 'a': case 'A':
                direction = LEFT;
                break;
            case 'd': case 'D':
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
    std::cout << "Level Score: " << levelScore << std::endl;
}

void Player::update(){
    input();
}
