#ifndef NORMAL_H_
#define NORMAL_H_

class Normal : public Enemy
{
  public:
    Normal();
    ~Normal();

    virtual void update(float);
};

#endif