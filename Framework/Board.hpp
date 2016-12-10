#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <iostream>
#include <vector>
#include "Box.hpp"
#include "../Exceptions/NotwellformedBoard.hpp"
#include "Enum_Direction/Direction.hpp"


#define KEYHAUT "z"
#define KEYBAS "s"
#define KEYGAUCHE "q"
#define KEYDROITE "d"

template <typename T>
class Board : public Box<T>{
public:
  Board();
  Board(int,int);
  int get_matrix_length_x();
  int get_matrix_length_y();
  std::vector <std::vector<Box<T>>>& get_plateau();
  void print();
  Direction do_one_move();
  operator std::vector <std::vector<Box<T>>>() const { return plateau; }
  void add_to_score(int);
  void reset_access();
private:
  int score;
  const int matrix_length_x;
  const int matrix_length_y;
  std::vector <std::vector<Box<T>>> plateau;
};

using namespace std;
#include "Board.cpp"

#endif
