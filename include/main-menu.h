#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#define MAIN_MENU_BUTTONS_QUANTITY 2

class MainMenu : public Menu
{
  public:
    MainMenu();
    ~MainMenu();

    virtual void run(Screen &) final;
    virtual void draw(Screen &) final;
};

#endif