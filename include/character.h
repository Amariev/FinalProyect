#ifndef CHARACTER_H_
#define CHARACTER_H_

enum Direction { UNKNOWN = 0, LEFT, RIGHT, UP, DOWN };

class Character : public Entity
{
  protected:
    Direction direction;
    Coord lastPosition;

  public:
    Character();
    ~Character();

    Coord getLastPosition() { return this->lastPosition; }


    void setDirection(Direction);
    void move();
    
    void update();
};

#endif
