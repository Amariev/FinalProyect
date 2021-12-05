#ifndef SMART_H_
#define SMART_H_

class Smart : public Enemy
{
  public:
    Smart();
    ~Smart();

    virtual void update();
};

#endif
