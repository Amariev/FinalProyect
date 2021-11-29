#ifndef BOMB_H_
#define BOMB_H_

class Bomb : public Ability
{
  public:
    int time;
    int tick; 

    Bomb();
    ~Bomb();

    void tickTime();
    void destroy();
};

#endif