#ifndef GAME_H_
#define GAME_H_

enum GameState { MENU = 0, GAME = 1, GAMEOVER = 2, END = 3};

class Game
{
  protected:
    Screen & screen;
    Database<Register> *registerDb;
    GameState state;

  public:
    Game(Screen &);
    ~Game();

    Screen & getScreen() { return this->screen; }

    GameState getState() { return this->state; }
    void setState(GameState state_) { this->state = state_; }

    void run();
    void save();
};

#endif
