#ifndef ARRAY_H_
#define ARRAY_H_

template<typename T>
class Array
{
  protected:
    int size;
    T *data;

  public:
    Array();
    Array(const T [], int);
    Array(const Array &);
    ~Array();

    int getSize() const;
    
    void push_back(T);
    T at(int);
    void remove(int);
};

template<typename T>
Array<T>::Array()
{
  this->size = 0;
  this->data = new T[0];
}

template<typename T>
Array<T>::Array(const T arr_[], int size_)
{
  this->size = size_;
  this->data = new T[this->size];
  for (int i = 0; i < this->size; i++)
    this->data[i] = arr_[i];
}

template<typename T>
Array<T>::Array(const Array & arr_)
{
  this->size = arr_.size;
  this->data = new T[arr_.size];
  for(int i = 0; i < size; i++)
    this->data[i] = arr_.data[i];
}

template <typename T>
Array<T>::~Array() {
    delete[] this->data;
}

template <typename T>
int Array<T>::getSize() const {
  return this->size;
}

template <typename T>
void Array<T>::push_back(T item_) {
    T *tmp = new T[size + 1];

    for(int i = 0; i < size; i++)
        tmp[i] = this->data[i];

    tmp[size] = item_;

    size += 1;
    
    delete [] this->data;
    
    this->data = tmp;
}

template <typename T>
T Array<T>::at(int index_)
{
  return this->data[index_];
}

template <typename T>
void Array<T>::remove(int index_) {
    this->data[index_] = this->data[index_ + 1];
    T *tmp = new T[size];

     for(int i = 0; i < this->size - 1; i++) {
        tmp[i] = this->data[i];
    }

    delete [] this->data;

    this->size -= 1;
    this->data = tmp;
} 

#endif
