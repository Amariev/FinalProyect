#ifndef ENTITY_H_
#define ENTITY_H_

class Entity
{
    protected:
      bool dead;
      bool canMove;
      int ID;

      Coord coords;

      std::string symbol;

    public:
      Entity();
      virtual ~Entity();

      int getID() { return this->ID; }

      Coord getCoords() { return this->coords; }

      void setCoords(Coord coords_) { this->coords = coords_; }

      bool isStable();
      bool isMoveable();
      bool isDead();
      bool destroy();
  
      std::string getSymbol() { return this->symbol; }

      virtual bool checkCollision(Entity *);
      virtual bool collision(Entity *) = 0;
      virtual void update(float) = 0;
};

#endif