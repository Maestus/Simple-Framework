#ifndef __MODULE_2048_HPP__
#define __MODULE_2048_HPP__
#include <iostream>
#include <random>
#include "../../Framework/Board.hpp"

class Module_2048 : public Board<int>{
public:
  Module_2048(int,int);
  virtual bool has_win();
  virtual void add_value() = 0;
  virtual bool apply_move(Direction);
  virtual void merge_tiles(Direction) = 0;
};

using namespace std;
#include "Module_2048.cpp"

#endif
