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
  int x;
  int y;
  if(argc == 3){
    const string & _x = argv[1];
    const string & _y = argv[2];
    try{
      x = stoi(_x);
      y = stoi(_y);
    }catch(exception &e){
      cout << "Donner des entiers en entrée" << endl;
      exit(1);
    }
  }
  cout << "-----------------------------------------------------------" << endl;
  cout << "-------------------WELCOME TRY MY GAME---------------------" << endl;
  cout << "-----------------------------------------------------------" << endl;

  try{
    Playclassic a(x,y);
    a.init(a.grid.get_matrix_length_x());
    a.grid.print();
  }catch(NotwellformedBoard &exception){
    cerr << exception.what() << exception.how() << endl;
  }
  return 0;
}
