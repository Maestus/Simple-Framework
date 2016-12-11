#ifndef __NEGATIVE_TILES__
#define __NEGATIVE_TILES__

#include "../lib/Module_2048.hpp"

class NegativeTiles : public Module_2048 {
private:
  const int valeur_initiale = 2;
  int negativetile;
public:
  NegativeTiles(int a, int b) : Module_2048(a,b), negativetile(-2){}
  virtual void init(int count);
  virtual void add_value();
  virtual void merge_tiles(Direction);
  void set_negativeTile(int);
  int get_negativeTile();
};

#include "NegativeTiles.cpp"

#endif
