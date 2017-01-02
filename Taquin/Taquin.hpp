#include <iostream>

#ifndef __BOARD__
#define __BOARD__
#include "../Framework/Board.hpp"
#endif

class Taquin : public Board<int>{
public:
  Taquin(int a, int b) : Board(a,b){}
  virtual void init();
  virtual bool apply_move(Direction);
  virtual bool has_win();
  virtual ~Taquin(){};
};
