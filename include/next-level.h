#ifndef next_level_h_
#define next_level_h_

class NextLevel : public Menu
{
  public:
    NextLevel(int);
    ~NextLevel();

    virtual void run(Screen &) final;
    virtual void draw(Screen &) final;
};

#endif
