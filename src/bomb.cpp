#include "../include/basic.h"

Bomb::Bomb()
{
  this->active = false;
  this->exploded = false;
  this->time = 0;
  this->tick = 0;
}

Bomb::~Bomb() 
{
    ;
}

void Bomb::tickTime(){
  time++;
  if(time%10 == 0){
    tick++;
    if(tick==3){
      destroy();
    }
  }  
}

void Bomb::destroy() {
  this->exploded = true;
  this->active = false;
}
