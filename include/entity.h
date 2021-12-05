#ifndef ENTITY_H_
#define ENTITY_H_

class Entity
{
    protected:
      Coord position;
 
    public:
      Entity();
      ~Entity();

      inline Coord getPosition() { return this->position; }
      inline void setPosition(Coord position_) { this->position = position_; }
};

#endif
