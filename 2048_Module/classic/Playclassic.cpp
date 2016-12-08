#include "Playclassic.hpp"

void Playclassic::init(int count){
  for(int i = 0; i < count; ++i){
    int x = -1;
    int y = -1;
    random_empty_pos(x, y);
    if(x == -1 && y == -1){
      return;
    }
    grid.get_plateau()[y][x] = ((random_integer(3) == 1) ? (valeur_initiale * valeur_initiale) : valeur_initiale);
  }
}

int main(int argc, char const *argv[]) {
  Playclassic a(5,9);
  a.init(3);
  a.grid.print();
  return 0;
}
