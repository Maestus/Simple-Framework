void Sokoban::init(){
  last_position_x = 0;
  last_position_y = 0;
  get_plateau()[last_position_x][last_position_y].set_content(personnage);
  nb_interrupteurs = (get_matrix_length_x()/2 < get_matrix_length_y()/2) ? get_matrix_length_x()/2 : get_matrix_length_y()/2;
  for(int i = 0; i < nb_interrupteurs*2; i++){
    int x = -1;
    int y = -1;
    random_empty_pos(x, y);
    if(x != -1 && y != -1){
      get_plateau()[x][y].set_content(mur);
    }
  }
  for(int i = 0; i < nb_interrupteurs; i++){
    int x = -1;
    int y = -1;
    random_empty_pos(x, y);
    if(x != -1 && y != -1){
      get_plateau()[x][y].set_content(interrupteur);
      interrupteurs.push_back( std::make_pair( x, y ) );
    }
  }
  for(int i = 0; i < nb_interrupteurs; i++){
    int x = -1;
    int y = -1;
    random_empty_pos(x, y);
    if(x != -1 && y != -1){
      get_plateau()[x][y].set_content(tonneau);
    }
  }
}

bool Sokoban::apply_move(Direction d){
  if(d == Direction::BAS){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y() ; ++y){
        if(get_plateau()[x][y].get_content() == personnage){
          if(x + 1 <= get_matrix_length_x() - 1 && get_plateau()[x+1][y].get_content() != mur){
            if(x + 2 <= get_matrix_length_x() - 1 && get_plateau()[x+1][y] == tonneau && get_plateau()[x+2][y] != tonneau && get_plateau()[x+2][y] != mur){
              if(!((x + 3 <= get_matrix_length_x() - 1) && get_plateau()[x+2][y] == tonneau)){
                get_plateau()[x+2][y].set_content(get_plateau()[x+1][y].get_content());
                get_plateau()[x+1][y].set_content(get_plateau()[x][y].get_content());
                last_position_x = x + 1;
                last_position_y = y ;
                if(std::find(interrupteurs.begin(), interrupteurs.end(), std::make_pair( x, y )) != interrupteurs.end())
                    get_plateau()[x][y].set_content(interrupteur);
                else
                  get_plateau()[x][y].set_content(' ');
                return true;
              }
            }
            else if(get_plateau()[x+1][y] != tonneau && get_plateau()[x+1][y] != mur){
              get_plateau()[x+1][y].set_content(get_plateau()[x][y].get_content());
              last_position_x = x + 1;
              last_position_y = y ;
              if(std::find(interrupteurs.begin(), interrupteurs.end(), std::make_pair( x, y )) != interrupteurs.end())
                  get_plateau()[x][y].set_content(interrupteur);
              else
                get_plateau()[x][y].set_content(' ');
              return true;
            }
          }
        }
      }
    }
  }else if(d == Direction::HAUT){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y() ; ++y){
        if(get_plateau()[x][y].get_content() == personnage){
          if(x - 1 >= 0 && get_plateau()[x-1][y].get_content() != mur){
            if(x - 2 >= 0 && get_plateau()[x-1][y] == tonneau && get_plateau()[x-2][y] != tonneau && get_plateau()[x-2][y] != mur){
              if(!((x - 3 >= 0) && get_plateau()[x-2][y] == tonneau)){
                get_plateau()[x-2][y].set_content(get_plateau()[x-1][y].get_content());
                get_plateau()[x-1][y].set_content(get_plateau()[x][y].get_content());
                last_position_x = x - 1;
                last_position_y = y ;
                if(std::find(interrupteurs.begin(), interrupteurs.end(), std::make_pair( x, y )) != interrupteurs.end())
                    get_plateau()[x][y].set_content(interrupteur);
                else
                  get_plateau()[x][y].set_content(' ');
                return true;
              }
            }
            else if(get_plateau()[x-1][y] != tonneau && get_plateau()[x-1][y] != mur){
              get_plateau()[x-1][y].set_content(get_plateau()[x][y].get_content());
              last_position_x = x - 1;
              last_position_y = y ;
              if(std::find(interrupteurs.begin(), interrupteurs.end(), std::make_pair( x, y )) != interrupteurs.end())
                  get_plateau()[x][y].set_content(interrupteur);
              else
                get_plateau()[x][y].set_content(' ');
              return true;
            }
          }
        }
      }
    }
  }else if(d == Direction::DROITE){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y() ; ++y){
        if(get_plateau()[x][y].get_content() == personnage){
          if(y + 1 <= get_matrix_length_y() - 1 && get_plateau()[x][y+1].get_content() != mur){
            if(y + 2 <= get_matrix_length_y() - 1 && get_plateau()[x][y+1] == tonneau &&  get_plateau()[x][y+2] != tonneau && get_plateau()[x][y+2] != mur){
              if(!((y + 3 <= get_matrix_length_y() - 1) && get_plateau()[x][y+2] == tonneau)){
                get_plateau()[x][y+2].set_content(get_plateau()[x][y+1].get_content());
                get_plateau()[x][y+1].set_content(get_plateau()[x][y].get_content());
                last_position_x = x;
                last_position_y = y + 1;
                if(std::find(interrupteurs.begin(), interrupteurs.end(), std::make_pair( x, y )) != interrupteurs.end())
                    get_plateau()[x][y].set_content(interrupteur);
                else
                  get_plateau()[x][y].set_content(' ');
                return true;
              }
            }
            else if(get_plateau()[x][y+1] != tonneau && get_plateau()[x][y+1] != mur){
              get_plateau()[x][y+1].set_content(get_plateau()[x][y].get_content());
              last_position_x = x;
              last_position_y = y + 1;
              if(std::find(interrupteurs.begin(), interrupteurs.end(), std::make_pair( x, y )) != interrupteurs.end())
                  get_plateau()[x][y].set_content(interrupteur);
              else
                get_plateau()[x][y].set_content(' ');
              return true;
            }
          }
        }
      }
    }
  }else if(d == Direction::GAUCHE){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y() ; ++y){
        if(get_plateau()[x][y].get_content() == personnage){
          if(y - 1 >= 0 && get_plateau()[x][y-1].get_content() != mur){
            if(y - 2 >= 0 && get_plateau()[x][y-1] == tonneau && get_plateau()[x][y-2] != tonneau && get_plateau()[x][y-2] != mur){
              if(!((y - 3 >= 0) && get_plateau()[x][y-2] == tonneau)){
                get_plateau()[x][y-2].set_content(get_plateau()[x][y-1].get_content());
                get_plateau()[x][y-1].set_content(get_plateau()[x][y].get_content());
                last_position_x = x;
                last_position_y = y - 1;
                if(std::find(interrupteurs.begin(), interrupteurs.end(), std::make_pair( x, y )) != interrupteurs.end())
                    get_plateau()[x][y].set_content(interrupteur);
                else
                  get_plateau()[x][y].set_content(' ');
                return true;
              }
            }
            else if(get_plateau()[x][y-1] != tonneau && get_plateau()[x][y-1] != mur){
              get_plateau()[x][y-1].set_content(get_plateau()[x][y].get_content());
              last_position_x = x;
              last_position_y = y - 1;
              if(std::find(interrupteurs.begin(), interrupteurs.end(), std::make_pair( x, y )) != interrupteurs.end())
                  get_plateau()[x][y].set_content(interrupteur);
              else
                get_plateau()[x][y].set_content(' ');
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}

bool Sokoban::has_win(){
  bool res = true;
  int nb_element = 0;
  for (int i = 0; i < get_matrix_length_x(); ++i){
    for (int j = 0; j < get_matrix_length_y(); ++j){
      if(get_plateau()[i][j].get_content() == interrupteur || get_plateau()[i][j].get_content() == tonneau)
        nb_element += 1;
      if(get_plateau()[i][j].get_content() == interrupteur)
        res = false;
    }
  }
  if(nb_element == nb_interrupteurs && !(std::find(interrupteurs.begin(), interrupteurs.end(), std::make_pair( last_position_x, last_position_y)) != interrupteurs.end()))
    return res;
  return false;
}
