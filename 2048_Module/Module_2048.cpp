#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
using namespace std;
#include "Module_2048.hpp"

Module_2048::Module_2048(int x_length, int y_length): grid(Board<int>(x_length,y_length)){}


/*bool Game::oneMove(int a){
  return true;
}*/

int random_integer(int n){
    srand (time(NULL));
    return rand() % n + 1;
}

void Module_2048::init(int count){
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


bool Module_2048::has_empty(){

    for(int x = 0; x < grid.get_matrix_length_x(); ++x){
      for(int y = 0; y < grid.get_matrix_length_y(); ++y){
        if(grid.get_plateau()[y][x] == 0){
                return true;
        }
      }
    }
    return false;
}


int Module_2048::getGridSize() {
  return grid.get_matrix_length_x()*grid.get_matrix_length_y();
}

// Gives a random position from [0, grid_size)
int Module_2048::rand_pos(){
  return random_integer(grid.get_matrix_length_x() - 1);
}

// Sets the x and y with a random empty position
void Module_2048::random_empty_pos(int& x, int& y){

    if(!has_empty()){
        return;
    }
    do{
        x = rand_pos();
        y = rand_pos();
        cout << x << " " << y << endl;
    }
    while(!(grid.get_plateau()[y][x] == 0));
}


int main(int argc, char const *argv[]) {
  int size;
  cout << "Entrer la taille de la grille que vous souhaitez avoir : ";
  cin >> size;
  Module_2048 m(size,size);
	m.grid.print();
  m.init(5);
  m.grid.get_plateau()[0][0] = 2;
  m.grid.print();
  return 0;
}
