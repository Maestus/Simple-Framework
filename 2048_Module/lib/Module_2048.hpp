#ifndef __MODULE_2048_HPP__
#define __MODULE_2048_HPP__

#include "../../Framework/Game.hpp"

class Module_2048 : public Board<int>{
public:
  Module_2048(int,int);
  int getGridSize() ;
  bool has_empty();
  int rand_pos();
  void random_empty_pos(int&, int&);
  virtual void init(int) = 0;
  int random_integer(int);
  Board<int> grid;
};

#include "Module_2048.cpp"

#endif
