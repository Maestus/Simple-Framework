Module_2048::Module_2048(int x_length, int y_length): grid(Board<int>(x_length,y_length)){}

int Module_2048::random_integer(int n){
  // Seed with a real random value, if available
  random_device r;
  // Choose a random mean between 1 and 6
  default_random_engine e1(r());
  uniform_int_distribution<int> uniform_dist(0, n);
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

bool Module_2048::apply_move(Direction d){
  bool has_moved = false;
  if(d == Direction::BAS){
    for(int x = grid.get_matrix_length_x() - 1; x >= 0; --x){
      for(int y = 0; y < grid.get_matrix_length_y(); ++y){
        if(!(grid.get_plateau()[x][y].get_content() == 0)){
          int lastx = x;
          int nextx = x + 1;
          while(nextx < grid.get_matrix_length_x() && grid.get_plateau()[nextx][y].get_content() == 0){
            lastx = nextx;
            ++nextx;
          }
          if(lastx != x){
            grid.get_plateau()[lastx][y].set_content(grid.get_plateau()[x][y].get_content());
            grid.get_plateau()[x][y].set_content(0);
            has_moved = true;
          }
        }
      }
    }
  }else if(d == Direction::HAUT){
    for(int x = 0; x < grid.get_matrix_length_x(); ++x){
      for(int y = 0; y < grid.get_matrix_length_y(); ++y){
        if(!(grid.get_plateau()[x][y].get_content() == 0)){
          int lastx = x;
          int nextx = x - 1;
          while(nextx >= 0 && grid.get_plateau()[nextx][y].get_content() == 0){
            lastx = nextx;
            --nextx;
          }
          if(lastx != x){
            grid.get_plateau()[lastx][y].set_content(grid.get_plateau()[x][y].get_content());
            grid.get_plateau()[x][y].set_content(0);
            has_moved = true;
          }
        }
      }
    }
  }else if(d == Direction::DROITE){
    for(int x = 0; x < grid.get_matrix_length_x(); ++x){
      for(int y = grid.get_matrix_length_y() - 1; y >= 0; --y){
        if(!(grid.get_plateau()[x][y] == 0)){
          int lasty = y;
          int nexty = y + 1;
          while(nexty < grid.get_matrix_length_y() && grid.get_plateau()[x][nexty] == 0){
            lasty = nexty;
            ++nexty;
          }
          if(lasty != y){
            grid.get_plateau()[x][lasty] = grid.get_plateau()[x][y];
            grid.get_plateau()[x][y] = 0;
          }
        }
      }
    }
  }else if(d == Direction::GAUCHE){
    for(int x = 0; x < grid.get_matrix_length_x(); ++x){
      for(int y = 0; y < grid.get_matrix_length_y(); ++y){
        if(!(grid.get_plateau()[x][y] == 0)){
          int lasty = y;
          int nexty = y - 1;
          while(nexty >= 0 && grid.get_plateau()[x][nexty] == 0){
            lasty = nexty;
            --nexty;
          }
          if(lasty != y){
            grid.get_plateau()[x][lasty] = grid.get_plateau()[x][y];
            grid.get_plateau()[x][y] = 0;
          }
        }
      }
    }
  }return has_moved;
}

// Gives the size of the Grid
int Module_2048::getGridSize() {
  return grid.get_matrix_length_x()*grid.get_matrix_length_y();
}

// Gives a random position from [0, grid_size]
int Module_2048::rand_pos(){
  return (grid.get_matrix_length_x() < grid.get_matrix_length_y()) ? random_integer(grid.get_matrix_length_x() - 1) : random_integer(grid.get_matrix_length_y() - 1);
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
