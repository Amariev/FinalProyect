#ifndef LEVEL_H_
#define LEVEL_H_

class Level 
{
  private:
    short levelNumber;
    bool isCompleted;    

    std::string levelName;

    Player *& player;
    Interface interface;

    Normal *enemies;
    int numberEnemies;

  public:
  	Level(Player *&, int);
	  ~Level();

    inline void setLevelNumber(unsigned short levelNumber_) { this->levelNumber = levelNumber_; }
    inline void setLevelName(const std::string levelName_) { this->levelName = levelName_; }

    void generateEnemy(Screen &);
    void updateLevel(float);
    void checkCollisions(Screen &);
    void nextLevel(Screen &);

    void update(Screen &);
    void draw(Screen &);

    bool play(Screen &, Player *&);
};

#endif
