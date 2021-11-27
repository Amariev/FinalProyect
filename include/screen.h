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

    void create(int, int, std::string);
    void draw(std::string);
    void display();
};

#endif
