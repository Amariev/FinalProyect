#ifndef BUTTON_H_
#define BUTTON_H_

class Button
{
    protected:
      std::string name;
      std::string icon;

    public:
      Button();
      ~Button();

      std::string getText() { return this->icon + " " + this->name; }

      void setColor();
      void setIcon(std::string icon_) { this->icon = icon_; }
      void setName(const std::string & name_) { this->name = name_; }
   
      void draw(Screen &);
};

#endif