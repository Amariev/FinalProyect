#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#define MAIN_MENU_BUTTONS_QUANTITY 2

class MainMenu : public Menu
{
  public:
    MainMenu();
    ~MainMenu();

    void run(Screen &) final;
    void draw(Screen &) final;
};

#endif
