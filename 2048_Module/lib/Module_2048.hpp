#ifndef __MODULE_2048_HPP__
#define __MODULE_2048_HPP__
#include <iostream>
#include <random>
#include "../../Framework/Game.hpp"

class Module_2048 : public Board<int>{
public:
  Module_2048(int,int);
  bool has_empty();
  int rand_pos();
  void random_empty_pos(int&, int&);
  virtual void init() = 0;
  virtual void add_value() = 0;
  bool apply_move(Direction);
  virtual void merge_tiles(Direction) = 0;
  int random_integer(int);
};

using namespace std;
#include "Module_2048.cpp"

#endif
