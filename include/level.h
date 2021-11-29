#ifndef LEVEL_H_
#define LEVEL_H_

class Level
{
  protected:
    int width;
    int height;
    short levelNumber;
    bool isActive;
    bool isCompleted;    
    int points;
    float time;

    std::string levelName;

    std::vector<Tile *> tiles;

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

    void resetPoints() { this->points = 0; }
    void resetTime() { this->time = 0; }

    int getPoints() { return this->points; }
    int getTime() { return this->time; }

    void generateMap(Screen &);
    void generateEnemy(Screen &);
    void updateLevel(float);
    void checkCollisions(Screen &);
    void update();
    void draw(Screen &);

    bool play(Screen &, Player *&);
};

#endif