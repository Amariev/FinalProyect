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

    int getButtonId() { return this->buttonId; }
    MenuState getMenuState() { return this->menuState; }

    void setMenuState(MenuState menuState_) { this->menuState = menuState_; };

    virtual void moveUp();
    virtual void moveDown(int);

    virtual void run(Screen &) = 0;
    virtual void draw(Screen &) = 0;
};

#endif