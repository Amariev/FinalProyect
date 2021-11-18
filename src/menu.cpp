#include "../include/menu.h"

// **************MENU***************

Menu::Menu()
{
    menuState = MAIN_MENU;
}

Menu::~Menu(){}

MenuState Menu::getMenuState()
{
    return this->menuState;
}
        
        
void Menu::setMenuState(MenuState new_menuState)
{
    this -> menuState = new_menuState;
}

void Menu::run(){}

void Menu::draw()
{
    cout << "\u250C";
    for(int i = 0; i < 11; ++i)
    {
        cout << "\u2500";
    }
    cout << "\u2510" << endl;
    cout << "\u2502" << "    MENU   " << "\u2502" << endl;
    cout << "\u2514";
    for(int i = 0; i < 11; ++i)
    {
        cout << "\u2500";
    }
    cout << "\u2518" << endl;
}

//****************MAIN_MENU********************

MainMenu::MainMenu():Menu(){}
MainMenu::~MainMenu(){}

void MainMenu::draw()
{
    Menu::draw();
    cout << "\u2776" << "   New Game" << endl;
    cout << "\u2777" << "   Score" << endl;
    cout << "\u2778" << "   Save" << endl;
    cout << "\u2779" << "   Exit" << endl;
    cout << "Elige una opcion" "\u27EB" " ";
}

void MainMenu::run()
{
    this->draw();
    int opcion;
    cin >> opcion;
     while (this->getMenuState() == MAIN_MENU)
     {
         switch(opcion){
             case 1:{
                 this->setMenuState(MenuState::PLAY);
                 return;
             }
         }
     }
}

//************PLAY*************
Play::Play()
{
    this->setMenuState(PLAY);
}

void Play::draw()
{
    // agregar opciones 
}

void Play::run()
{
    //agregar 
}
