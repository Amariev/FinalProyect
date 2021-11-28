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
  topLine(16, true);
  // cout << "\u2502" << "     MENU     " << "\u2502" << endl;
  cout << "\u2551" << "     MENU     " << "\u2551" << endl;
  bottomLine(16, true);  
}

/* void Menu::space(int num) {
    for(int i=0; i<num ; i++){
        std::cout << " ";
    }
} */

void Menu::topLine(int width,bool temp){
    std::string mark1="\u2500",mark2="\u250C",mark3="\u2510";
    if (temp) {
      mark1 = "\u2550";
      mark2 = "\u2554";
      mark3 = "\u2557";
    }
    for(int i=0;i<width;i++)
    {
        if(i==0)  cout<<mark2;
        else if(i==width-1) cout<<mark3;
        else cout<<mark1;
    }
    std::cout << std::endl;
}

void Menu::bottomLine(int width, bool temp) {
    std::string mark1="\u2500", mark2="\u2514",  mark3="\u2518";
    if (temp) {
      mark1 = "\u2550";
      mark2 = "\u255A";
      mark3 = "\u255D";
    }
    for(int i=0;i<width;i++)
    {
        if(i==0)  cout<<mark2;
        else if(i==width-1) cout<<mark3;
        else cout<<mark1;
    }
    std::cout << std::endl;
}

/* void textString(int width, std::string text){
    int lenght = text.size();
    
} */

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
      case 2:{
        break;
      }
      case 3:{
        break;
      }
      case 4:{
        this->setMenuState(MenuState::EXIT);
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
