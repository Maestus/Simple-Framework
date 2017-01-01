void TwoThreeFiveTiles::init(){
  for(int i = 0; i < 2; ++i){
    int x = -1;
    int y = -1;
    random_empty_pos(x, y);
    if(x == -1 && y == -1){
      return;
    }
    get_plateau()[x][y] = ((random_integer(2) == 1) ? ((random_integer(2) == 1) ? valeur_initiale[0] : valeur_initiale[1]) : valeur_initiale[2]);
  }
}

void TwoThreeFiveTiles::add_value(){
  int x = -1;
  int y = -1;
  random_empty_pos(x, y);
  if(y == -1 && x == -1) return;
  get_plateau()[x][y] = ((random_integer(2) == 1) ? ((random_integer(2) == 1) ? valeur_initiale[0] : valeur_initiale[1]) : valeur_initiale[2]);
}

void TwoThreeFiveTiles::merge_tiles(Direction d){
  if(d == Direction::BAS){
    for(int x = get_matrix_length_x() - 1; x >= 0; --x){
      for(int y = 0; y < get_matrix_length_y() ; ++y){
        if(!(get_plateau()[x][y].get_content() == 0)){
          int lastx = x;
          int nextx = x - 1;
          while(nextx >= 0 && get_plateau()[nextx][y].get_content() == 0){
            lastx = nextx;
            --nextx;
          }
          if(nextx >= 0 && get_plateau()[nextx][y].get_content() == get_plateau()[x][y].get_content()
            && !get_plateau()[nextx][y].is_access() && !get_plateau()[x][y].is_access()){
            get_plateau()[x][y].set_content(get_plateau()[nextx][y].get_content()
              *(((get_plateau()[nextx][y].get_content() % 3 == 0) ? valeur_initiale[1] : ((get_plateau()[nextx][y].get_content() % 5 == 0) ? valeur_initiale[2] : valeur_initiale[0]))));
            add_to_score(get_plateau()[nextx][y].get_content());
            get_plateau()[x][y].set_access(true);
            get_plateau()[nextx][y].set_content(0);
          }
        }
      }
    }
  }else if(d == Direction::HAUT){
    for(int x = 0 ; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y() ; ++y){
        if(!(get_plateau()[x][y] == 0)){
          int lastx = x;
          int nextx = x + 1;
          while(nextx < get_matrix_length_x() && get_plateau()[nextx][y] == 0){
            lastx = nextx;
            ++nextx;
          }
          if(nextx < get_matrix_length_x() && get_plateau()[nextx][y] == get_plateau()[x][y] && !get_plateau()[nextx][y].is_access() && !get_plateau()[x][y].is_access()){
            get_plateau()[nextx][y] = get_plateau()[x][y]
              *((get_plateau()[nextx][y].get_content() % 3 == 0) ? valeur_initiale[1] : ((get_plateau()[nextx][y].get_content() % 5 == 0) ? valeur_initiale[2] : valeur_initiale[0]));
            add_to_score(get_plateau()[nextx][y].get_content());
            get_plateau()[nextx][y].set_access(true);
            get_plateau()[x][y] = 0;
          }
        }
      }
    }
  }else if(d == Direction::DROITE){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = get_matrix_length_y() - 1; y >= 0; --y){
        if(!(get_plateau()[x][y] == 0)){
          int lasty = y;
          int nexty = y - 1;
          while(nexty >= 0 && get_plateau()[x][nexty] == 0){
            lasty = nexty;
            --nexty;
          }
          if(nexty >= 0 && get_plateau()[x][nexty] == get_plateau()[x][y]
            && !get_plateau()[x][nexty].is_access() && !get_plateau()[x][y].is_access()){
            get_plateau()[x][nexty] = get_plateau()[x][y]
              *((get_plateau()[x][y].get_content() % 3 == 0) ? valeur_initiale[1] : ((get_plateau()[x][y].get_content() % 5 == 0) ? valeur_initiale[2] : valeur_initiale[0]));
            add_to_score(get_plateau()[x][nexty].get_content());
            get_plateau()[x][nexty].set_access(true);
            get_plateau()[x][y] = 0;
          }
        }
      }
    }
  }else if(d == Direction::GAUCHE){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y(); ++y){
        if(!(get_plateau()[x][y] == 0)){
          int lasty = y;
          int nexty = y + 1;
          while(nexty < get_matrix_length_y() && get_plateau()[x][nexty] == 0){
            lasty = nexty;
            ++nexty;
          }
          if(nexty < get_matrix_length_y() && get_plateau()[x][nexty] == get_plateau()[x][y]
            && !get_plateau()[x][nexty].is_access() && !get_plateau()[x][y].is_access()){
            get_plateau()[x][nexty] = get_plateau()[x][y]
              *((get_plateau()[x][y].get_content() % 3 == 0) ? valeur_initiale[1] : ((get_plateau()[x][y].get_content() % 5 == 0) ? valeur_initiale[2] : valeur_initiale[0]));
            add_to_score(get_plateau()[x][nexty].get_content());
            get_plateau()[x][nexty].set_access(true);
            get_plateau()[x][y] = 0;
          }
        }
      }
    }
  }
}
