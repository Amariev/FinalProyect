#ifndef BUTTON_H_
#define BUTTON_H_

class Button 
{
    private:
      std::string name;
      std::string icon;

    public:
      Button();
      ~Button();

      inline std::string getText() { return this->icon + " " + this->name; }

      inline void setIcon(std::string icon_) { this->icon = icon_; }
      inline void setName(const std::string & name_) { this->name = name_; }
   
      void draw(Screen &);
};

#endif
