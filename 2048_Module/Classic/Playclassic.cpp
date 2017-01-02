#include "Playclassic.hpp"

void Playclassic::init(){
  for(int i = 0; i < 2; ++i){
    int x = -1;
    int y = -1;
    random_empty_pos(x, y);
    if(x == -1 && y == -1){
      return;
    }
    get_plateau()[x][y] = ((random_integer(3) == 1) ? (valeur_initiale * valeur_initiale) : valeur_initiale);
  }
}

void Playclassic::add_value(){
  int x = - 1;
  int y = - 1;
  random_empty_pos(x, y);
  if(y == -1 && x == -1) return;
  get_plateau()[x][y] = ((random_integer(3) == 1) ? (valeur_initiale * valeur_initiale) : valeur_initiale);
}

void Playclassic::merge_tiles(Direction d){
  if(d == Direction::BAS){
    for(int x = get_matrix_length_x() - 1; x >= 0; --x){
      for(int y = 0; y < get_matrix_length_y() ; ++y){
        if(!(get_plateau()[x][y].get_content() == 0)){
          int nextx = x - 1;
          while(nextx >= 0 && get_plateau()[nextx][y].get_content() == 0){
            --nextx;
          }
          if(nextx >= 0 && get_plateau()[nextx][y].get_content() == get_plateau()[x][y].get_content()
            && !get_plateau()[nextx][y].is_access() && !get_plateau()[x][y].is_access()){
            get_plateau()[x][y].set_content(get_plateau()[nextx][y].get_content()*valeur_initiale);
            add_to_score(get_plateau()[x][y].get_content());
            get_plateau()[x][y].set_access(true);
            get_plateau()[nextx][y].set_content(0);
          }
        }
      }
    }
  }else if(d == Direction::HAUT){
    for(int x = 0 ; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y(); ++y){
        if(!(get_plateau()[x][y] == 0)){
          int nextx = x + 1;
          while(nextx < get_matrix_length_x() && get_plateau()[nextx][y] == 0){
            ++nextx;
          }
          if(nextx < get_matrix_length_x() && get_plateau()[nextx][y] == get_plateau()[x][y]
            && !get_plateau()[nextx][y].is_access() && !get_plateau()[x][y].is_access()){
            get_plateau()[nextx][y] = get_plateau()[x][y]*valeur_initiale;
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
          int nexty = y - 1;
          while(nexty >= 0 && get_plateau()[x][nexty] == 0){
            --nexty;
          }
          if(nexty >= 0 && get_plateau()[x][nexty] == get_plateau()[x][y]
            && !get_plateau()[x][nexty].is_access() && !get_plateau()[x][y].is_access()){
            get_plateau()[x][nexty] = get_plateau()[x][y]*valeur_initiale;
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
          int nexty = y + 1;
          while(nexty < get_matrix_length_y() && get_plateau()[x][nexty] == 0){
            ++nexty;
          }
          if(nexty < get_matrix_length_y() && get_plateau()[x][nexty] == get_plateau()[x][y]
            && !get_plateau()[x][nexty].is_access() && !get_plateau()[x][y].is_access()){
            get_plateau()[x][nexty] = get_plateau()[x][y]*valeur_initiale;
            add_to_score(get_plateau()[x][nexty].get_content());
            get_plateau()[x][nexty].set_access(true);
            get_plateau()[x][y] = 0;
          }
        }
      }
    }
  }
}
