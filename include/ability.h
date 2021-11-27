#ifndef ABILITY_H_
#define ABILITY_H_

class Ability : public Stable
{
  protected:
    Coord coords;
  
  public:
    Ability();
    virtual ~Ability();

    virtual void draw();
    virtual bool collision(Entity *);
    virtual void update(float);
};

#endif