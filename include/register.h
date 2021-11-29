#ifndef REGISTER_H
#define REGISTER_H

#include <fstream>
using namespace std;

class Register
{
  public: 
  Register(string, int);

  void setName(string);
  void setScore(int);
  void getName();
  void getScore();

  // void escribir();

  private:
  string name;
  int score; 
}
#endif