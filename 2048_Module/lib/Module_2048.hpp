#include "../../Framework/Game.hpp"

class Module_2048 : public Board<int>{

public:
  const static int valeur_initiale = 2;
  int getGridSize() ;
  bool has_empty();
  int rand_pos();
  void random_empty_pos(int&, int&);
  void init(int);
  Module_2048(int,int);
  Board<int> grid;
};
