#ifndef NEXT_LEVEL_H_
#define NEXT_LEVEL_H_

class NextLevel : public Menu
{
  public:
    NextLevel(int);
    ~NextLevel();

    virtual void run(Screen &) final;
    virtual void draw(Screen &) final;
};

#endif