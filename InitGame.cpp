#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "2048_Module/Classic/Playclassic.hpp"
#include "2048_Module/ThreeAndFiveTiles/TwoThreeFiveTiles.hpp"
#include "2048_Module/NegativeTiles/NegativeTiles.hpp"
#include "Taquin/Taquin.hpp"

#define BORDURE "##############################################################"

Module_2048* launch_2048_module(int& x, int& y){
  cout << "-----------------------------------------------------------" << endl;
  cout << "-                       Launching                         -" << endl;
  cout << "-                      2048-Module                        -" << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "#  1 - Classic mode                                       #" << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "#  2 - TwoThreeFiveTiles mode                             #" << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "#  3 - NegativeTiles mode                                 #" << endl;
  cout << "-----------------------------------------------------------" << endl;
  int choix;
  cout << "Faite votre choix : ";
  try{
    cin >> choix;
  }catch(exception const& e){
    cout << e.what() << endl;
  }
  if(choix == 1)
    return new Playclassic(x,y);
  else if(choix == 2)
    return new TwoThreeFiveTiles(x,y);
  return new NegativeTiles(x,y);
}

int main(int argc, char const *argv[]) {
  int x = 0;
  int y = 0;
  string game_name;
  bool instantiation = false;
  if(argc == 4){
    game_name = argv[1];
    const string & _x = argv[2];
    const string & _y = argv[3];
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
    if(game_name == "2048"){
      Module_2048 *a = launch_2048_module(x,y);
      a->init();
      a->print();
      while(1){
        Direction choice = Direction::NOTKNOWN;
        choice = a->do_one_move();
        if(!(choice == Direction::NOTKNOWN)){
          a->merge_tiles(choice);
          cout << BORDURE << endl;
          cout << "score : " << a->get_score() << endl;
          cout << BORDURE << endl;
          a->print();
          if(a->has_win()){
            cout << "~~~~~~~~~~~~~~~~ You Win ! ~~~~~~~~~~~~~~~~~~~" << endl;
            exit(0); // Need to give the choice to the player to replay
          }
        }
      }
    }else if(game_name == "Taquin"){
      Taquin *a = new Taquin(x,y);
      a->init();
      a->print();
    }
  }catch(NotwellformedBoard &exception){
    if(!instantiation){
      cout << "Executer le programme comme suit : ./game x_value y_value" << endl;
    }else
      cerr << exception.what() << exception.how() << endl;
  }
  return 0;
}
