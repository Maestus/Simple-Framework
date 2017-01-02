#ifndef __MODULE_2048__
#define __MODULE_2048__
#include "../lib/Module_2048.hpp"
#endif

class TwoThreeFiveTiles : public Module_2048 {
private:
  const int valeur_initiale[3] = {2,3,5};
public:
  TwoThreeFiveTiles(int a, int b) : Module_2048(a,b){}
  virtual void init();
  virtual void add_value();
  virtual void merge_tiles(Direction);
};
