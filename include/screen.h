#ifndef SCREEN_H_
#define SCREEN_H_

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
    void draw(Entity *);
    void draw(std::string);
    void display();
};

#endif
