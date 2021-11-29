#ifndef MOVEABLE_H_
#define MOVEABLE_H_

class Moveable : public Entity
{
  protected:
    Coord lastPosition;

  public:
    Moveable();
    virtual ~Moveable();

    Coord getLastPosition() { return this->lastPosition; }

    virtual void draw() = 0;
    virtual bool collision(Entity *) = 0;
    virtual void update();
};

#endif