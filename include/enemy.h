#ifndef ENEMY_H_
#define ENEMY_H_

class Enemy : public Character
{
  public:
    Enemy();
    ~Enemy();
    
    void setRandomDirection();
    void update();
};

#endif
