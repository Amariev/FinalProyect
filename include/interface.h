#ifndef INTERFACE_H_
#define INTERFACE_H_

class Interface
{
  Player *& player;

  std::vector <Button *> buttons;

  public:
    Interface(Player *&);
    ~Interface();

    void draw(Screen &);
    void update(float);
};

#endif