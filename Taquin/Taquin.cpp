void Taquin::init(){
  int length = (get_matrix_length_x()*get_matrix_length_y());
  int list_of_number[length];
  do{
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
  }while(!has_solution());
}

void Taquin::get_greatest_element(int a,int res[2],std::vector<std::vector<int>> t){
  int search = a;
  for (int i = get_matrix_length_x() - 1; i >= 0; --i){
    for (int j = get_matrix_length_y() - 1; j >=0; --j){
      if(search == t[i][j]){
        res[0] = i;
        res[1] = j;
        return;
      }
    }
  }
}

int Taquin::zero_no_hikariga(){
  int pos = 1;
  for (int i = get_matrix_length_x() - 1; i >= 0; --i){
    for (int j = get_matrix_length_y() - 1; j >=0; --j){
      if(0 == get_plateau()[i][j].get_content())
        return pos;
      pos++;
    }
  }
}

bool Taquin::has_solution(){
  int inv_count = 0;
  int number = get_matrix_length_x()*get_matrix_length_y();
  std::vector<std::vector<int>> solution(get_matrix_length_x(),vector<int>(get_matrix_length_y()));
  for (int i = get_matrix_length_x() - 1; i >= 0; --i){
    for (int j = get_matrix_length_y() - 1; j >=0; --j){
      solution[i][j] = get_plateau()[i][j].get_content();
    }
  }
  int tmp = solution[get_matrix_length_x()-1][get_matrix_length_y()-1];
  int tab[2];
  get_greatest_element(0,tab,solution);
  solution[get_matrix_length_x()-1][get_matrix_length_y()-1] = 0;
  solution[tab[0]][tab[1]] = tmp;
  inv_count++;
  number = 1;
  for (int i = get_matrix_length_x() - 1; i >= 0; --i){
    std::vector<std::vector<int>> solution2 = solution;
    for (int j = get_matrix_length_y() - 1; j >=0; --j){
      if(solution[i][j] != (i*get_matrix_length_x()) + (j+1)){
        if(!(i == get_matrix_length_x() - 1 && j == get_matrix_length_y() - 1)){
          int tmp = solution[i][j];
          solution[i][j] = (i*get_matrix_length_x()) + (j+1);
          int tab[2];
          get_greatest_element((i*get_matrix_length_x()) + (j+1),tab,solution2);
          solution[tab[0]][tab[1]] = tmp;
          inv_count++;
        }
      }
    }
  }
  return (((get_matrix_length_x() % 2 != 0) && (get_matrix_length_y() % 2 != 0))  && (inv_count % 2 == 0)) || (((get_matrix_length_x() % 2 == 0) && (get_matrix_length_y() % 2 == 0))  && ((zero_no_hikariga() % 2 != 0) == (inv_count % 2 == 0)));
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
  return true;
}


void Taquin::print(){
  int max_min = 0;
  for(int i = 0; i < get_matrix_length_x(); ++i){
    for(int j = 0; j < get_matrix_length_y(); ++j){
      if(get_plateau()[i][j].get_content() > max_min)
        max_min = get_plateau()[i][j].get_content();
      if(-get_plateau()[i][j].get_content() > max_min)
        max_min = -get_plateau()[i][j].get_content();
    }
  }
  string espacement = "      ";
  for(int i = 0; i < get_matrix_length_x(); i++){
    if(i>0)
      cout << endl;
    for(int j = 0; j < get_matrix_length_y(); j++){
      if(get_plateau()[i][j].get_content() == 0){
         cout << espacement << ".";
      }else{
        if(get_plateau()[i][j].get_content() >= 10000){
          string espacement2 = espacement.substr(0,espacement.size()-4);
          cout << espacement2 << get_plateau()[i][j].get_content();
        }else if(get_plateau()[i][j].get_content() >= 1000 && get_plateau()[i][j].get_content() < 10000){
          string espacement2 = espacement.substr(0,espacement.size()-3);
          cout << espacement2 << get_plateau()[i][j].get_content();
        }else if(get_plateau()[i][j].get_content() >= 100 && get_plateau()[i][j].get_content() < 1000){
          string espacement2 = espacement.substr(0,espacement.size()-2);
          cout << espacement2 << get_plateau()[i][j].get_content();
        }else if(get_plateau()[i][j].get_content() >= 10 && get_plateau()[i][j].get_content() < 100){
          string espacement2 = espacement.substr(0,espacement.size()-1);
          cout << espacement2 << get_plateau()[i][j].get_content();
        }else cout << espacement << get_plateau()[i][j].get_content();
      }
    }
  }
  cout << endl;
}
