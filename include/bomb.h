#ifndef BOMB_H_
#define BOMB_H_

class Bomb : public Ability
{
  private:
    int time;
    int tick;
    bool exploded;

  public:
    Bomb();
    ~Bomb();

    inline bool isExploded(){return exploded;}
    void tickTime();
    void destroy();
};

#endif
