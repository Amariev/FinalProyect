#include "../include/basic.h"

Normal::Normal() { ; }
Normal::~Normal() { ; }

void Normal::update() {
  this->lastPosition = position;
  this->move();
}