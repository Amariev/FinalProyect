#ifndef RESOURCES_H_
#define RESOURCES_H_
  
class Resources
{
  public :
    static std::string databasePath(std::string fileName_) 
      { return "../database/" + fileName_; }
      
    static std::string getUUID()
    {
        return "1b4e28ba-2fa1-11d2-883f-0016d3cca427";
    }
};

#endif
