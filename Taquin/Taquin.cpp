void Taquin::init(){
  int length = (get_matrix_length_x()*get_matrix_length_y());
  int list_of_number[length];
  bool empty_box = false;
  for(int i = 0; i < length; ++i){
    list_of_number[i] = i;
  }
  for(int i = 0; i < get_matrix_length_x(); ++i){
    for(int j = 0; j < get_matrix_length_y(); ++j){
      int random = random_integer(length-1);
      if(!empty_box && (random == 0)){
        get_plateau()[i][j].set_content(0);
        empty_box = true;
      }else {
        if(i == get_matrix_length_x() - 1 && j == get_matrix_length_y() - 1 && !empty_box){
          get_plateau()[i][j].set_content(0);
          empty_box = true;
        }else{
          while(list_of_number[random] == 0){
            random = random_integer(length-1);
          }
          get_plateau()[i][j].set_content(list_of_number[random]);
          list_of_number[random] = 0;
        }
      }
    }
  }
}

bool Taquin::apply_move(Direction d){
  if(d == Direction::BAS){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y() ; ++y){
        if(get_plateau()[x][y].get_content() == 0){
          if(x - 1 >= 0){
            get_plateau()[x][y].set_content(get_plateau()[x-1][y].get_content());
            get_plateau()[x-1][y].set_content(0);
            return true;
          }
        }
      }
    }
  }else if(d == Direction::HAUT){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y() ; ++y){
        if(get_plateau()[x][y].get_content() == 0){
          if(x + 1 < get_matrix_length_x()){
            get_plateau()[x][y].set_content(get_plateau()[x+1][y].get_content());
            get_plateau()[x+1][y].set_content(0);
            return true;
          }
        }
      }
    }
  }else if(d == Direction::DROITE){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y() ; ++y){
        if(get_plateau()[x][y].get_content() == 0){
          if(y - 1 >= 0){
            get_plateau()[x][y].set_content(get_plateau()[x][y-1].get_content());
            get_plateau()[x][y-1].set_content(0);
            return true;
          }
        }
      }
    }
  }else if(d == Direction::GAUCHE){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y() ; ++y){
        if(get_plateau()[x][y].get_content() == 0){
          if(y + 1 < get_matrix_length_y()){
            get_plateau()[x][y].set_content(get_plateau()[x][y+1].get_content());
            get_plateau()[x][y+1].set_content(0);
            return true;
          }
        }
      }
    }
  }
  return false;
}

bool Taquin::has_win(){
  int value = 1;
  for (int i = 0; i < get_matrix_length_x(); ++i){
    for (int j = 0; j < get_matrix_length_y(); ++j){
      if(i == get_matrix_length_x() - 1 && j == get_matrix_length_y() - 1)
        return (get_plateau()[i][j] == 0);
      else if(get_plateau()[i][j].get_content() != value)
        return false;
      value++;
    }
  }
  return Board<int>::has_win();
}
