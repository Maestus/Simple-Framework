void TwoThreeFiveTiles::init(int count){
  for(int i = 0; i < count; ++i){
    int x = -1;
    int y = -1;
    random_empty_pos(x, y);
    if(x == -1 && y == -1){
      return;
    }
    grid.get_plateau()[y][x] = ((random_integer(2) == 1) ? ((random_integer(2) == 1) ? valeur_initiale[0] : valeur_initiale[1]) : valeur_initiale[2]);
  }
}

void TwoThreeFiveTiles::add_value(){
  int x;
  int y;
  random_empty_pos(x, y);
  grid.get_plateau()[y][x] = ((random_integer(2) == 1) ? ((random_integer(2) == 1) ? valeur_initiale[0] : valeur_initiale[1]) : valeur_initiale[2]);
}

void TwoThreeFiveTiles::merge_tiles(Direction d){
  bool has_merged = false;
  if(d == Direction::BAS){
    for(int x = grid.get_matrix_length_x() - 1; x >= 0; --x){
      for(int y = 0; y < grid.get_matrix_length_y() ; ++y){
        if(!(grid.get_plateau()[x][y].get_content() == 0)){
          int lastx = x;
          int nextx = x - 1;
          while(nextx >= 0 && grid.get_plateau()[nextx][y].get_content() == 0){
            lastx = nextx;
            --nextx;
          }
          if(nextx >= 0 && grid.get_plateau()[nextx][y].get_content() == grid.get_plateau()[x][y].get_content()
            && !grid.get_plateau()[nextx][y].is_access() && !grid.get_plateau()[x][y].is_access()){
            grid.get_plateau()[x][y].set_content(grid.get_plateau()[nextx][y].get_content()
              *(((grid.get_plateau()[nextx][y].get_content() % 3 == 0) ? valeur_initiale[1] : ((grid.get_plateau()[nextx][y].get_content() % 5 == 0) ? valeur_initiale[2] : valeur_initiale[0]))));
            grid.get_plateau()[x][y].set_access(true);
            grid.get_plateau()[nextx][y].set_content(0);
            has_merged = true;
          }
        }
      }
    }
  }else if(d == Direction::HAUT){
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
            grid.get_plateau()[nextx][y] = grid.get_plateau()[x][y]
              *((grid.get_plateau()[nextx][y].get_content() % 3 == 0) ? valeur_initiale[1] : ((grid.get_plateau()[nextx][y].get_content() % 5 == 0) ? valeur_initiale[2] : valeur_initiale[0]));
            grid.get_plateau()[nextx][y].set_access(true);
            grid.get_plateau()[x][y] = 0;
            has_merged = true;
          }
        }
      }
    }
  }else if(d == Direction::DROITE){
    for(int x = 0; x < grid.get_matrix_length_x(); ++x){
      for(int y = 0; y < grid.get_matrix_length_y(); ++y){
        if(!(grid.get_plateau()[x][y] == 0)){
          int lasty = y;
          int nexty = y + 1;
          while(nexty < grid.get_matrix_length_y() && grid.get_plateau()[x][nexty] == 0){
            lasty = nexty;
            ++nexty;
          }
          if(nexty < grid.get_matrix_length_y() && grid.get_plateau()[x][nexty] == grid.get_plateau()[x][y]
            && !grid.get_plateau()[x][nexty].is_access() && !grid.get_plateau()[x][y].is_access()){
            grid.get_plateau()[x][nexty] = grid.get_plateau()[x][y]
              *((grid.get_plateau()[x][y].get_content() % 3 == 0) ? valeur_initiale[1] : ((grid.get_plateau()[x][y].get_content() % 5 == 0) ? valeur_initiale[2] : valeur_initiale[0]));
            grid.get_plateau()[x][nexty].set_access(true);
            grid.get_plateau()[x][y] = 0;
            has_merged = true;
          }
        }
      }
    }
  }else if(d == Direction::GAUCHE){
    for(int x = 0; x < grid.get_matrix_length_x(); ++x){
      for(int y = grid.get_matrix_length_y() - 1; y >= 0; --y){
        if(!(grid.get_plateau()[x][y] == 0)){
          int lasty = y;
          int nexty = y - 1;
          while(nexty >= 0 && grid.get_plateau()[x][nexty] == 0){
            lasty = nexty;
            --nexty;
          }
          if(nexty >= 0 && grid.get_plateau()[x][nexty] == grid.get_plateau()[x][y]
            && !grid.get_plateau()[x][nexty].is_access() && !grid.get_plateau()[x][y].is_access()){
            grid.get_plateau()[x][nexty] = grid.get_plateau()[x][y]
              *((grid.get_plateau()[x][y].get_content() % 3 == 0) ? valeur_initiale[1] : ((grid.get_plateau()[x][y].get_content() % 5 == 0) ? valeur_initiale[2] : valeur_initiale[0]));
            grid.get_plateau()[x][nexty].set_access(true);
            grid.get_plateau()[x][y] = 0;
            has_merged = true;
          }
        }
      }
    }
  }
  if(has_merged | apply_move(d))
    add_value();
  grid.reset_access();
}
