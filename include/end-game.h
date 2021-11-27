#ifndef END_GAME_H_
#define END_GAME_H_

class EndGame
{
  public:
    EndGame(int, float);
    ~EndGame();

    virtual void run(Screen &) final;
    virtual void draw(Screen &) final;
};

#endif