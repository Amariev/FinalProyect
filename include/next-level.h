#ifndef next_level_h_
#define next_level_h_

class NextLevel : public Menu
{
  public:
    NextLevel();
    ~NextLevel();

    void run(Screen &);
    void draw(Screen &);
};

#endif
