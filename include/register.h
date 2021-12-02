#ifndef REGISTER_H_
#define REGISTER_H_

#include <string>

class Register 
{
  private:
    std::string ID;
    std::string score;
    
  public:
    Register(std::string, std::string);
    Register(std::string []);
    ~Register();

    std::string getID() { return this->ID; }
    std::string getScore() { return this->score; }
    std::string toString() { return this->ID + "|" + this->score; }
};

#endif
