#include <iostream>

template <class T>
class Box{
public:
  Box():box(T()){}
  Box(T a):box(a){}

  bool operator==(int b){
    return b == box;
  }

  operator T() { return box; }

  Box<T>& operator=(const Box<T>& b){
    if (this->box != b.box) {
          this->box = b.box;
      }
      std::cout << "-****"<<*this<<"****-"<< std::endl;
      return *this;
  }

private:
  T box;
friend std::ostream& operator<<(std::ostream& out,const Box<T> &b){
  return (out<<b.box);
}
};
