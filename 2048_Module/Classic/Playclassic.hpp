#ifndef __PLAY_CLASSIC__
#define __PLAY_CLASSIC__

#include "../lib/Module_2048.hpp"

class Playclassic : public Module_2048 {
private:
  const int valeur_initiale = 2;
public:
  Playclassic(int a, int b) : Module_2048(a,b){}
  virtual void init();
  virtual void add_value();
  virtual void merge_tiles(Direction);
};

#include "Playclassic.cpp"

#endif
