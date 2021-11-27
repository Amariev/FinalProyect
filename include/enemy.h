#ifndef ENEMY_H_
#define ENEMY_H_

class Enemy : public Character
{
  public:
    Enemy();
    virtual ~Enemy();
    
    Enemy * getEnemy();
    virtual void update(float);
};

#endif