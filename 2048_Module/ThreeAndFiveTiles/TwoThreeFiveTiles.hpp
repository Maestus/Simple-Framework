#ifndef __TWO_THREE_FIVE__
#define __TWO_THREE_FIVE__

#include "../lib/Module_2048.hpp"

class TwoThreeFiveTiles : public Module_2048 {
private:
  const int valeur_initiale[3] = {2,3,5};
public:
  TwoThreeFiveTiles(int a, int b) : Module_2048(a,b){}
  virtual void init();
  virtual void add_value();
  virtual void merge_tiles(Direction);
};

#include "TwoThreeFiveTiles.cpp"

#endif
