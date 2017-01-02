#ifndef __MODULE_2048__
#define __MODULE_2048__
#include "../lib/Module_2048.hpp"
#endif

class Playclassic : public Module_2048 {
private:
  const int valeur_initiale = 2;
public:
  Playclassic(int a, int b) : Module_2048(a,b){}
  virtual void init();
  virtual void add_value();
  virtual void merge_tiles(Direction);
};
