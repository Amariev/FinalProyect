#ifndef ENGINE_H_
#define ENGINE_H_

#define LEVELS_QUANTITY 7
#define STARTING_LEVEL_NUMBER 1

class Engine 
{
    private:
      int totalLevels;
      int currentLevel;
      bool running;

      std::vector <Level *> levels;
      Player * player;

    public:
      Engine(Screen &);
      ~Engine();

      void run(Screen &);
      bool play(Screen &, Level *);
};

#endif
