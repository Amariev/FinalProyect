#ifndef LEVEL_H_
#define LEVEL_H_

class Level
{
  protected:
    int width;
    int height;
    short levelNumber;
    
    int points;
    float time;

    Screen & screen;
    Player *& player;
    Interface interface;

  public:
  	Level(Screen &, Player *&);
	  ~Level();

    void resetPoints() { this->points = 0; }
    void resetTime() { this->time = 0; }

    int getPoints() { return this->points; }
    int getTime() { return this->time; }

    void generate(Screen &);
    bool play(Screen &, Player *&);
};

#endif