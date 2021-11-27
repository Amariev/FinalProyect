#ifndef STABLE_H_
#define STABLE_H_

enum Interaction { NONE = 0, STOP, BONUS, DAMAGE, TELEPORT };

#define BONUS_POINTS 25

class Stable : public Entity
{
  protected:
    bool collidable;
    bool interactable;
    Interaction interaction;

  public:
    Stable();
    virtual ~Stable();

    bool isCollidable();
    bool isInteractable();

    virtual void draw();
    virtual bool collision(Entity *);
    virtual void update(float);
};

#endif

