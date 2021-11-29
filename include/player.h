#ifndef PLAYER_H_
#define PLAYER_H_

class Player : public Character
{
  protected:
    int usedBombs;
    int availableBombs;
    int currentBombId;
    bool abilityCast;
    Bomb *bombs;
    int numberBombs;

    public:
      Player(int);
      virtual ~Player();
      
      int getUsedBombs() { return this->usedBombs; }
      Bomb * getBombs() { return this->bombs; }
      int getAvailableBombs() { return this->availableBombs; }
      int getCurrentBombId() { return this->currentBombId; }
      bool isAbilityCast() { return this->abilityCast; }
      int getTotalBombs() { return this->numberBombs; }

      void setBombPosition();
      void setUsedBombs(int usedBombs_) { this->usedBombs = usedBombs_; }
      void setAvailableBombs(int availableBombs_) { this->availableBombs = availableBombs_; }
      void setAbilityCast(bool abilityCast_) { this->abilityCast = abilityCast_; }

      virtual void update();
      virtual bool castAbility();
};

#endif