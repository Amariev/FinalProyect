#ifndef DATABASE_H_
#define DATABASE_H_

#include <fstream>
#include <sstream>
#include "../util/array.h"

template<typename T>
class Database
{
  protected:
    const std::string fileName;
    const int propertySize;
    Array<T *> source;

  public:
    Database(const std::string, const int);
    ~Database();

    void read();
    void write();

    Array<T *> getAll();
    T * getOne(int);
};

template<typename T>
Database<T>::Database(std::string fileName_, int propertySize_): fileName(fileName_), propertySize (propertySize_)
{
  ;
}

template<typename T>
Database<T>::~Database()
{
  ;
}

template<typename T>
void Database<T>::read()
{
  const std::string delimiter = "|";
  std::ifstream file(this->fileName);
  std::string line;

  std::string properties[this->propertySize];

  while (std::getline(file, line))
  {
    std::stringstream ssin(line);
    int index_properties = 0;
    size_t position = 0;
    while ((position = line.find(delimiter)) != std::string::npos)
    {
      std::string value = line.substr(0, position);
      properties[index_properties] = value;
      ++index_properties;
      line.erase(0, position + delimiter.length());
    }
    properties[index_properties] = line;

    T *const item = new T(properties);

    this->source.push_back(item);
  }

  file.close();
}

template<typename T>
void Database<T>::write()
{
    std::ofstream ofs;
    ofs.open(this->fileName, std::ofstream::out);
    for ( int i = 0; i < this->source.getSize() ; ++i) { 
      ofs << this->source.at(i)->toString() << std::endl;
    }
    ofs.close();
}

template<typename T>
Array<T *> Database<T>::getAll()
{
  return this->source;
}

template<typename T>
T * Database<T>::getOne(int index_)
{
  return this->source.at(index_);
}

#endif