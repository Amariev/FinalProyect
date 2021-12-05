#ifndef GAME_OVER_H_
#define GAME_OVER_H_

#define GAME_OVER_BUTTONS_QUANTITY 3

class GameOver : public Menu
{
    public:
      GameOver();
      ~GameOver();

    void run(Screen &);
    void draw(Screen &);
};

#endif
