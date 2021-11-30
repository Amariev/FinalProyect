#ifndef LEVEL_H_
#define LEVEL_H_

class Level
{
  protected:
    short levelNumber;
    bool isCompleted;    

    std::string levelName;

    Screen & screen;
    Player *& player;
    Interface interface;

    Normal *enemies;
    int numberEnemies;

  public:
  	Level(Screen &, Player *&, int);
	  ~Level();

    void setLevelNumber(unsigned short levelNumber_) { this->levelNumber = levelNumber_; }
	  void setLevelName(const std::string levelName_) { this->levelName = levelName_; }

    void generateEnemy(Screen &);
    void updateLevel(float);
    void checkCollisions(Screen &);

    void update(Screen &);
    void draw(Screen &);

    bool play(Screen &, Player *&);
};

#endif
