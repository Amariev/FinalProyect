#ifndef ENGINE_H_
#define ENGINE_H_

#define LEVELS_QUANTITY 7
#define STARTING_LEVEL_NUMBER 1

class Engine
{
    protected:
      int totalLevels;
      int currentLevel;
      bool running;
      Stats totalStats;

      long delay;

      std::vector <Level *> levels;
      Player * player;

    public:
      Engine(Screen &);
      ~Engine();

      void updateScore(int);
      void updateTime(float);

      int getPoints() { return this->totalStats.pts; }
      float getTime() { return this->totalStats.tm; }

      void run(Screen &);
      bool play(Screen &, Level *);
};

#endif