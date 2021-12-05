#ifndef MENU_H_
#define MENU_H_

enum MenuState { MAIN_MENU = 0, PLAY, EXIT, NEXT, GAME_OVER, OUT, SAVE = 6 };

class Menu
{
  protected:
    int buttonId;

    std::vector<Button *> buttons;

    MenuState menuState;

  public:
    Menu();
    virtual ~Menu();

    inline int getButtonId() { return this->buttonId; }
    inline MenuState getMenuState() { return this->menuState; }

    inline void setMenuState(MenuState menuState_) { this->menuState = menuState_; };

    void moveUp();
    void moveDown(int);

    virtual void run(Screen &) = 0;
};

#endif
