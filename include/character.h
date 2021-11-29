#ifndef CHARACTER_H_
#define CHARACTER_H_

enum Direction { UNKNOWN = 0, LEFT, RIGHT, UP, DOWN };

class Character : public Moveable
{
  protected:
    Direction direction;
    
    float moveSpeed;
    bool pendingAbility;

  public:
    Character();
    virtual ~Character();

    void setDirection(bool);
    void setCollisionState(bool);

    void move(Coord coords_);
    
    virtual void draw();
    virtual bool collision(Entity *);
    virtual void update();
};

#endif