#include <iostream>
#include <random>
using namespace std;

Module_2048::Module_2048(int x_length, int y_length): grid(Board<int>(x_length,y_length)){}

int Module_2048::random_integer(int n){
  // Seed with a real random value, if available
  random_device r;

  // Choose a random mean between 1 and 6
  default_random_engine e1(r());
  uniform_int_distribution<int> uniform_dist(1, n);
  return uniform_dist(e1);
}


//Return True if there is an empty Box
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

// Gives the size of the Grid
int Module_2048::getGridSize() {
  return grid.get_matrix_length_x()*grid.get_matrix_length_y();
}

// Gives a random position from [0, grid_size]
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
    }
    while(!(grid.get_plateau()[y][x] == 0));
}
