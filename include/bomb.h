#ifndef BOMB_H_
#define BOMB_H_

class Bomb : public Ability
{
  public:
    int time;
    int tick;
    bool exploded;   

    Bomb();
    ~Bomb();

    inline bool isExploded(){return exploded;}
    void tickTime();
    void destroy();
};

#endif
