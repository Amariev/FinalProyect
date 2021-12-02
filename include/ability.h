#ifndef ABILITY_H_
#define ABILITY_H_

class Ability : public Entity
{
  protected:
    bool active;
  
  public:
    Ability();
    ~Ability();

    bool isActive(){ return active; }
    void setActive(bool active_){ active = active_; }
};

#endif
