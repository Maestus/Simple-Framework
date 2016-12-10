#ifndef __PLAY_CLASSIC__
#define __PLAY_CLASSIC__

#include "../lib/Module_2048.hpp"

class Playclassic : public Module_2048 {
private:
  const int valeur_initiale [1] = {2};
public:
  Playclassic(int a, int b) : Module_2048(a,b){}
  virtual void init(int count);
  virtual void apply_move(Direction);
  virtual void add_value();
};

#include "Playclassic.cpp"

#endif
