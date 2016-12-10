#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "2048_Module/classic/Playclassic.hpp"

#define BORDURE "##############################################################"

int main(int argc, char const *argv[]) {
  int x = 0;
  int y = 0;
  bool instantiation = false;
  if(argc == 3){
    const string & _x = argv[1];
    const string & _y = argv[2];
    try{
      x = stoi(_x);
      y = stoi(_y);
      instantiation = true;
    }catch(exception &e){
      cout << "Donner des entiers en entrée" << endl;
      exit(1);
    }
  }
  try{
    Playclassic a(x,y);
    a.init(a.grid.get_matrix_length_x()/2);

    cout << "-----------------------------------------------------------" << endl;
    cout << "-                   2048-Classic                          -" << endl;
    cout << "-----------------------------------------------------------" << endl;

    a.grid.print();
    while(1){
      Direction choice = Direction::NOTKNOWN;
      choice = a.do_one_move();
      if(!(choice == Direction::NOTKNOWN)){
        cout << BORDURE << endl;
        a.merge_tiles(choice);
        a.grid.print();
      }
    }
  }catch(NotwellformedBoard &exception){
    if(!instantiation){
      cout << "Executer le programme comme suit : ./Playclassic x_value y_value" << endl;
    }else
      cerr << exception.what() << exception.how() << endl;
  }
  return 0;
}
