#ifndef CHARACTER_H_
#define CHARACTER_H_

enum Direction { UNKNOWN = 0, LEFT, RIGHT, UP, DOWN };

class Character : public Moveable
{
  protected:
    std::string name;
  
    Coord movement;
    Coord lastMovement;

    Direction lastDirection;
    
    float moveSpeed;
    bool pendingAbility;

  public:
    Character();
    virtual ~Character();

    Direction getLastDirection();
    Coord getLastMovement();

    void setX(int);
    void setY(int);
    void setName(const std::string &name_) { this->name = name_; };
    void setDirection(bool);
    void setCollisionState(bool);

    void move(Coord coords_);
    
    virtual void draw();
    virtual bool collision(Entity *);
    virtual void update(float);
};

#endif