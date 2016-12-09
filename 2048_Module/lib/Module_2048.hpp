#ifndef __MODULE_2048_HPP__
#define __MODULE_2048_HPP__
#include <iostream>
#include <random>
#include "../../Framework/Game.hpp"

class Module_2048 : public Board<int>{
public:
  Module_2048(int,int);
  int getGridSize() ;
  bool has_empty();
  int rand_pos();
  void random_empty_pos(int&, int&);
  virtual void init(int) = 0;
  virtual void add_value() = 0;
  virtual void apply_move(Direction) = 0;
  int random_integer(int);
  Board<int> grid;
};

using namespace std;
#include "Module_2048.cpp"

#endif
