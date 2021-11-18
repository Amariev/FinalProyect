#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

enum MenuState
{
    MAIN_MENU = 0,
    PLAY = 1,
    RESUME = 2,
    SAVE = 3,
    EXIT = 4,
    GAME_OVER = 5,
    OUT = 6
};

class Menu
{
    protected:
        MenuState menuState;
    public:
        Menu();
        ~Menu();
        MenuState getMenuState();
        void setMenuState(MenuState);

        virtual void run();
        virtual void draw();
};

#endif

class MainMenu : public Menu
{
  public:
    MainMenu();
    ~MainMenu();

    void run();
    void draw();
};

class Play : public Menu
{
    public:
    Play();
    ~Play();

    void run();
    void draw();
};

class Exit : public Menu
{
  public:
    Exit();
    ~Exit();

    void run();
    void draw();

};

class GameOver : public Menu
{
  public:
    GameOver();
    ~GameOver();

    void run();
    void draw();
};
