#ifndef BOMB_H_
#define BOMB_H_

enum BombState { normal, explosion, disappear };

class Bomb : public Ability
{
  public:
    int time;
    int tick;
    BombState state;

    Bomb();
    ~Bomb();

    void tickTime();
    void destroy();
};

#endif
