#ifndef SCREEN_H_
#define SCREEN_H_

enum TileType { BLANK = 0, STONE, PLAYER, ENEMY };

class Screen
{
  protected:
    int width;
    int height;
    std::string name;

    int **self;

  public:
    Screen();
    ~Screen();

    int getWidth() { return this->width; }
    int getHeight() { return this->height; }
    int ** getSelf() { return this->self; }

    void create(int, int, std::string);
    void assignEntity(Coord, Coord, TileType);
    void draw(Entity *);
    void draw(std::string);
    void display();
};

#endif
