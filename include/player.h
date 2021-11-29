#ifndef PLAYER_H_
#define PLAYER_H_

class Player : public Character
{
  protected:
    bool abilityCast;

    public:
      Player();
      virtual ~Player();
      
      bool isAbilityCast();
      float getLastCast();

      Player * getPlayer();

      virtual void update();

      virtual bool castAbility();
      virtual Ability * getAbility();
};

#endif