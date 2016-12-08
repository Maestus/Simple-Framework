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
  int x = 0;
  int y = 0;
  cout << "-----------------------------------------------------------" << endl;
  cout << "---------------WELCOME TRY MY FUCKING GAME-----------------" << endl;
  cout << "-----------------------------------------------------------" << endl;

  initialization :
    init_x :
      cout << "Entrer le nombre de ligne du plateau : ";
      cin >> x;
      if(cin.fail()){
        cerr << "Entrer un entier !!" << endl;
        cin.clear();
        goto init_x;
      }
    cout << "Entrer le nombre de colonne du plateau : ";
    init_y :
        cin >> y;
        if(cin.fail()){
          cerr << "Entrer un entier !!" << endl;
          cin.clear();
          goto init_y;
        }
  try{
    Playclassic a(x,y);
    a.init(a.grid.get_matrix_length_x());
    a.grid.print();
  }catch(NotwellformedBoard &exception){
    cerr << exception.what() << exception.how() << endl;
    goto initialization;
  }
  return 0;
}
