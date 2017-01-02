#ifndef __SOKOBAN__
#define __SOKOBAN__

#include <iostream>
#include <algorithm>
#include <vector>
#include "../Framework/Board.hpp"

class Sokoban : public Board<char>{
public:
  Sokoban(int a, int b, char perso= 'P', char inter = 'I', char ton = 'T') : Board(a,b), personnage(perso), interrupteur(inter), tonneau(ton){}
  virtual void init();
  virtual bool apply_move(Direction);
  char get_void_value(){return void_value;}
  virtual bool has_win();
  virtual ~Sokoban(){
    // erase interrupteurs
  };
private:
  std::vector <std::pair <int, int>> interrupteurs;
  char personnage;
  char interrupteur;
  char tonneau;
  int last_position_x;
  int last_position_y;
  char void_value = ' ';
  int nb_interrupteurs = 0;
};

using namespace std;
#include "Sokoban.cpp"

#endif
