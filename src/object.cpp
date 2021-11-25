#include "../include/object.h"
#include <string>

Object::Object(){}

Object::Object(Coord _pos, std::string _symbol){
    this->pos = _pos;
    this->symbol = _symbol;
}

Object::Object(Object &o) {
    this->pos = o.pos;
    this->symbol = o.symbol;
}

void Object::setPos(Coord _pos) { this->pos = _pos; }

void Object::setSymbol(std::string _symbol) { this->symbol = _symbol; }

std::string Object::getSymbol() { return symbol; }

Coord Object::getPos() { return pos; }

void Object::printAttributes(){
    std::cout << "Pos X: " << pos.X << std::endl;
    std::cout << "Pos Y: " << pos.Y << std::endl;
    std::cout << "Symbol: " << symbol << std::endl;
}
