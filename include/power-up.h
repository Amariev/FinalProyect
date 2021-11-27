#ifndef POWER_UP_H_
#define POWER_UP_H_

class PowerUp : public Stable
{
  public:
    PowerUp();
    ~PowerUp();

    virtual bool collision(Entity *);
};

#endif
