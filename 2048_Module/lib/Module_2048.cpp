Module_2048::Module_2048(int x_length, int y_length): Board(x_length, y_length){}

bool Module_2048::apply_move(Direction d){
  merge_tiles(d);
  bool has_moved = false;
  if(d == Direction::BAS){
    for(int x = get_matrix_length_x() - 1; x >= 0; --x){
      for(int y = 0; y < get_matrix_length_y(); ++y){
        if(!(get_plateau()[x][y].get_content() == 0)){
          int lastx = x;
          int nextx = x + 1;
          while(nextx < get_matrix_length_x() && get_plateau()[nextx][y].get_content() == 0){
            lastx = nextx;
            ++nextx;
          }
          if(lastx != x){
            get_plateau()[lastx][y].set_content(get_plateau()[x][y].get_content());
            get_plateau()[x][y].set_content(0);
            has_moved = true;
          }
        }
      }
    }
  }else if(d == Direction::HAUT){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y(); ++y){
        if(!(get_plateau()[x][y].get_content() == 0)){
          int lastx = x;
          int nextx = x - 1;
          while(nextx >= 0 && get_plateau()[nextx][y].get_content() == 0){
            lastx = nextx;
            --nextx;
          }
          if(lastx != x){
            get_plateau()[lastx][y].set_content(get_plateau()[x][y].get_content());
            get_plateau()[x][y].set_content(0);
            has_moved = true;
          }
        }
      }
    }
  }else if(d == Direction::DROITE){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = get_matrix_length_y() - 1; y >= 0; --y){
        if(!(get_plateau()[x][y] == 0)){
          int lasty = y;
          int nexty = y + 1;
          while(nexty < get_matrix_length_y() && get_plateau()[x][nexty] == 0){
            lasty = nexty;
            ++nexty;
          }
          if(lasty != y){
            get_plateau()[x][lasty] = get_plateau()[x][y];
            get_plateau()[x][y] = 0;
            has_moved = true;
          }
        }
      }
    }
  }else if(d == Direction::GAUCHE){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y(); ++y){
        if(!(get_plateau()[x][y] == 0)){
          int lasty = y;
          int nexty = y - 1;
          while(nexty >= 0 && get_plateau()[x][nexty] == 0){
            lasty = nexty;
            --nexty;
          }
          if(lasty != y){
            get_plateau()[x][lasty] = get_plateau()[x][y];
            get_plateau()[x][y] = 0;
            has_moved = true;
          }
        }
      }
    }
  }
  add_value();
  reset_access();
  return has_moved;
}

//Test of there is a tile with the value is 2048
bool Module_2048::has_win(){
  for(int i = 0; i < get_matrix_length_x(); ++i){
    for(int j = 0; j < get_matrix_length_y(); ++j){
      if(get_plateau()[i][j].get_content() == 2048)
        return Board<int>::has_win();
    }
  }
  return false;
}
