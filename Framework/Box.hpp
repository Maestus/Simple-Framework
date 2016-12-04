#include <iostream>

template <class T>
class Box{
public:
  Box():box(T()){}
  Box(T a):box(a){}

  bool operator==(int b){
    std::cout << "----"<<b<<"----"<< std::endl;
    return b == box;
    std::cout << "--PASS--" << std::endl;
  }

  operator T() { return box; }

  void operator=(int b){
    if (this->box != &b) {
          delete box; // free resource;
          box = 0;
          box = b;
      }
      return *this;
  }

private:
  T box;
friend std::ostream& operator<<(std::ostream& out,const Box<T> &b){
  return (out<<b.box);
}
};
