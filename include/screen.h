#ifndef SCREEN_H_
#define SCREEN_H_

enum TileType { BLANK = 0, STONE, PLAYER, ENEMY, BOMB, FIRE };

class Screen 
{
  private:
    int width;
    int height;

    int **self;

  public:
    Screen();
    ~Screen();

    void generateMap();

    inline int getWidth() { return this->width; }
    inline int getHeight() { return this->height; }
    inline int ** getSelf() { return this->self; }

    void create(int, int);
    void assignEntity(Coord, TileType);
    void assignEntity(Coord, Coord, TileType);
    void draw(std::string);
    void draw();
    void display();
};

#endif
