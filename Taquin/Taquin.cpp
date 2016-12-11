void Taquin::init(){
  int length = (get_matrix_length_x()*get_matrix_length_y());
  int list_of_number[length];
  for(int i = 0; i < length; ++i){
    list_of_number[i] = i;
  }
  while(!has_solution()){ //Need to be implemented
    for(int i = 0; i < get_matrix_length_x(); ++i){
      for(int j = 0; j < get_matrix_length_y(); ++j){
        if( i == get_matrix_length_x() - 1 && j == get_matrix_length_y() - 1)
          get_plateau()[i][j].set_content(0);
        else{
          int random = random_integer(length-1);
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


bool Taquin::has_solution(){
  return true;
}


bool Taquin::apply_move(Direction){
  return true;
}

bool Taquin::has_win(){
  return true;
}
