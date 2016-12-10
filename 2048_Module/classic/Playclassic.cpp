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

//int get_multiple(int) Abstraite le type de case (commence à 2 ou à 3) renvoi le PPCM

void Playclassic::add_value(){
  int x;
  int y;
  random_empty_pos(x, y);
  grid.get_plateau()[y][x] = ((random_integer(3) == 1) ? (valeur_initiale * valeur_initiale) : valeur_initiale);
}

void Playclassic::apply_move(Direction d){
  if(d == Direction::BAS){
    bool moved = true;
    while(moved){
      moved = false;
      for(int x = 0; x < grid.get_matrix_length_x(); ++x){
        for(int y = 0; y < grid.get_matrix_length_y() ; ++y){
          if(!(grid.get_plateau()[x][y] == 0)){
            int lastx = x;
            int nextx = x + 1;
            while(nextx < grid.get_matrix_length_x() && grid.get_plateau()[nextx][y] == 0){
              lastx = nextx;
              ++nextx;
            }
            if(nextx < grid.get_matrix_length_x() && grid.get_plateau()[nextx][y] == grid.get_plateau()[x][y]
              && !grid.get_plateau()[nextx][y].is_access() && !grid.get_plateau()[x][y].is_access()){
              grid.get_plateau()[nextx][y] = grid.get_plateau()[x][y]*(get_multiple(grid.get_plateau()[x][y]));
              grid.get_plateau()[nextx][y].set_access(true);
              grid.get_plateau()[x][y] = 0;
              moved = true;
            }else if(lastx != x){
              grid.get_plateau()[lastx][y] = grid.get_plateau()[x][y];
              grid.get_plateau()[x][y] = 0;
              moved = true;
            }
          }
        }
      }
    }
  }
  if(d == Direction::HAUT){
    bool moved = true;
    while(moved){
      moved = false;
      for(int x = grid.get_matrix_length_x() - 1; x >= 0; --x){
        for(int y = 0; y < grid.get_matrix_length_y() ; ++y){
          if(!(grid.get_plateau()[x][y] == 0)){
            int lastx = x;
            int nextx = x - 1;
            while(nextx >= 0 && grid.get_plateau()[nextx][y] == 0){
              lastx = nextx;
              --nextx;
            }
            if(nextx >= 0 && grid.get_plateau()[nextx][y] == grid.get_plateau()[x][y]
              && !grid.get_plateau()[nextx][y].is_access() && !grid.get_plateau()[x][y].is_access()){
              grid.get_plateau()[nextx][y] = grid.get_plateau()[x][y]*valeur_initiale;
              grid.get_plateau()[nextx][y].set_access(true);
              grid.get_plateau()[x][y] = 0;
              moved = true;

            }else if(lastx != x){
              grid.get_plateau()[lastx][y] = grid.get_plateau()[x][y];
              grid.get_plateau()[x][y] = 0;
              moved = true;
            }
          }
        }
      }
    }
  }
  add_value();
  grid.reset_access();
}
