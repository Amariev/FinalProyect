#ifndef PLAYER_H_
#define PLAYER_H_

class Player : public Character
{
  private:
    int usedBombs;
    int availableBombs;
    int currentBombId;
    bool abilityCast;
    Bomb *bombs;
    int numberBombs;

    public:
      Player();
      ~Player();
      
      inline int getUsedBombs() { return this->usedBombs; }
      inline Bomb * getBombs() { return this->bombs; }
      inline int getAvailableBombs() { return this->availableBombs; }
      inline int getCurrentBombId() { return this->currentBombId; }
      inline bool isAbilityCast() { return this->abilityCast; }
      inline int getTotalBombs() { return this->numberBombs; }

      void setBombPosition();
      inline void setUsedBombs(int usedBombs_) { this->usedBombs = usedBombs_; }
      void reloadBombs(int);
      inline void setAvailableBombs(int availableBombs_) { this->availableBombs = availableBombs_; }
      inline void setAbilityCast(bool abilityCast_) { this->abilityCast = abilityCast_; }

      void update();
      void castAbility();
};

#endif
