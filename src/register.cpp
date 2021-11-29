#include "../include/basic.h"

Register::Register(std::string ID_, std::string score_)
{
  this->ID = ID_;
  this->score = score_;
}

Register::Register(std::string args[])
{
  this->ID = args[0];
  this->score = args[1];
}

Register::~Register()
{
  ;
}