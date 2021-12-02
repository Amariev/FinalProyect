#ifndef ENTITY_H_
#define ENTITY_H_

class Entity
{
    protected:
      Coord position;

      std::string symbol;

    public:
      Entity();
      virtual ~Entity();

      Coord getPosition() { return this->position; }

      void setPosition(Coord position_) { this->position = position_; }

      bool destroy();
  
      std::string getSymbol() { return this->symbol; }

      virtual void update();
};

#endif
