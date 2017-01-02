#ifndef __TAQUIN__
#define __TAQUIN__

#include <iostream>
#include "../Framework/Board.hpp"

class Taquin : public Board<int>{
public:
  Taquin(int a, int b, int e=0) : Board(a,b), void_value(e){}
  virtual void init();
  virtual void print();
  virtual bool apply_move(Direction);
  int get_void_value(){return void_value;}
  virtual bool has_win();
  virtual ~Taquin(){};
private:
  int void_value = 0;
};

using namespace std;
#include "Taquin.cpp"

#endif
