#include <iostream>
#include <random>

#ifndef __BOARD__
#define __BOARD__
#include "../../Framework/Board.hpp"
#endif

class Module_2048 : public Board<int>{
public:
  Module_2048(int,int);
  virtual bool has_win();
  virtual bool has_lose();
  virtual void add_value() = 0;
  virtual bool apply_move(Direction);
  virtual void merge_tiles(Direction) = 0;
};
