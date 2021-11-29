#ifndef ENTITY_H_
#define ENTITY_H_

class Entity
{
    protected:
      bool dead;
      bool canMove;
      int ID;

      Coord position;

      std::string symbol;

    public:
      Entity();
      virtual ~Entity();

      int getID() { return this->ID; }

      Coord getPosition() { return this->position; }

      void setPosition(Coord position_) { this->position = position_; }

      bool isStable();
      bool isMoveable();
      bool isDead();
      bool destroy();
  
      std::string getSymbol() { return this->symbol; }

      virtual bool checkCollision(Entity *);
      virtual bool collision(Entity *) = 0;
      virtual void update();
};

#endif