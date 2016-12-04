#include "Box.hpp"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Board : public Box<T>{
public:
  Board();
  Board(int,int);
  int get_matrix_length_x();
  int get_matrix_length_y();
  std::vector <std::vector<Box<T>>> get_plateau();
  void print();
  operator std::vector <std::vector<Box<T>>>() const { return plateau; }
private:
  const int matrix_length_x;
  const int matrix_length_y;
  vector <vector<Box<T>>> plateau;
};

template <class T>
Board<T>::Board():matrix_length_x(), matrix_length_y(), plateau(){};

template <class T>
Board<T>::Board(int a, int b): matrix_length_x(a), matrix_length_y(b), plateau(matrix_length_x,vector<Box<T>>(matrix_length_y) ){}

template <typename T>
int Board<T>::get_matrix_length_x(){
  return matrix_length_x;
}

template <typename T>
int Board<T>::get_matrix_length_y(){
  return matrix_length_y;
}


template <typename T>
void Board<T>::print(){
  for(int i = 0; i < matrix_length_x; i++){
    if(i>0)
      cout << endl;
    for(int j = 0; j < matrix_length_y; j++)
      cout << plateau[i][j];
  }
  cout << endl;
}

template <typename T>
std::vector <std::vector<Box<T>>> Board<T>::get_plateau(){
  return this->plateau;
}
