#include <iostream>

template <class T>
class Box{
public:
  Box():content(T()){}
  Box(T a):content(a){}

  bool operator==(int b){
    return b == content;
  }

  operator T() { return content; }

  Box<T>& operator=(const Box<T>& b){
    if (this->content != b.content) {
      this->content = b.content;
      }
      return *this;
  }
private:
  T content;
friend std::ostream& operator<<(std::ostream& out,const Box<T> &b){
  return (out<<b.content);
}
};
