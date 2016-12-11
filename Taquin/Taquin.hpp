#ifndef __TAQUIN__
#define __TAQUIN__

#include <iostream>
#include "../Framework/Board.hpp"

class Taquin : public Board<int>{
public:
  Taquin(int a, int b) : Board(a,b){}
  bool has_solution();
  void get_greatest_element(int, int []);
  virtual void init();
  virtual bool apply_move(Direction);
  virtual bool has_win();
};

using namespace std;
#include "Taquin.cpp"

#endif
