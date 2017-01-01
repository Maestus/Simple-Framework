template <typename T>
Board<T>::Board(int a, int b): score(), matrix_length_x(a), matrix_length_y(b), enable_computer_play(){
  if(a <= 1 || b <= 1){
    throw NotwellformedBoard(matrix_length_x,matrix_length_y);
  }
  plateau = new Box<T>*[matrix_length_x];
  for(int i = 0; i < matrix_length_x; i++){
    plateau[i] = new Box<T>[matrix_length_y];
  }
}

template <typename T>
Board<T>::~Board(){
  for(int i = 0; i < matrix_length_x; i++)
    delete [] plateau[i];
}

template <typename T>
void Board<T>::set_enable_computer_play(){
  enable_computer_play = true;
  computer_play();
}

template <typename T>
int Board<T>::random_integer(int n){
  // Seed with a real random value, if available
  random_device r;
  // Choose a random mean between 1 and n
  default_random_engine e1(r());
  uniform_int_distribution<int> uniform_dist(0, n);
  return uniform_dist(e1);
}

template <typename T>
void Board<T>::add_to_score(int points){
  score += points;
}

template <typename T>
int Board<T>::get_score(){
  return score;
}

template <typename T>
int Board<T>::getGridSize() {
  return matrix_length_x*matrix_length_y;
}

template <typename T>
void Board<T>::reset_access(){
  for(int i = 0; i < matrix_length_x; i++){
    for(int j = 0; j < matrix_length_y; j++)
      plateau[i][j].set_access(false);
  }
}

template <typename T>
int Board<T>::get_matrix_length_x(){
  return matrix_length_x;
}

template <typename T>
int Board<T>::get_matrix_length_y(){
  return matrix_length_y;
}

template <typename T>
void Board<T>::computer_play(){
  string input;
  Direction d;
  while (!has_win() && !has_lose()) {
    d = get_random_direction();
    apply_move(d);
    cout << "#################   "  << d <<  "   ##################" << endl;
    if(score > 0){
      cout << "#####################################################" << endl;
      cout << "score : " << score << endl;
      cout << "#####################################################" << endl;
    }
    print();
    if(has_win()){
      cout << "~~~~~~~~~~~~~~~~ You Win ! ~~~~~~~~~~~~~~~~~~~" << endl;
    } else if(has_lose()) {
      cout << "~~~~~~~~~~~~~~~~ You Lose ! ~~~~~~~~~~~~~~~~~~~" << endl;
    }
    cout << "Wish to continue ? [Y/N] : ";
    cin >> input;
    if(input != "Y"){
      return;
    }
  }
}

template <typename T>
Direction Board<T>::get_random_direction(){
  int i = random_integer(3);
  if( i == 0 )
    return Direction::HAUT;
  if( i == 1 )
    return Direction::BAS;
  if( i == 2 )
    return Direction::GAUCHE;
  return Direction::DROITE;
}

template <typename T>
Direction Board<T>::do_one_move(){
  string choice;
  cin >> choice;
  if(choice == KEYDROITE){
    return Direction::DROITE;
  }if(choice == KEYGAUCHE){
    return Direction::GAUCHE;
  }if(choice == KEYHAUT){
    return Direction::HAUT;
  }if(choice == KEYBAS){
    return Direction::BAS;
  }
  return Direction::NOTKNOWN;
}


template <typename T>
Box<T>** Board<T>::get_plateau(){
  return this->plateau;
}

template <typename T>
void Board<T>::print(){
  for(int i = 0; i < get_matrix_length_x(); i++){
    if(i>0)
      cout << endl;
    for(int j = 0; j < get_matrix_length_y(); j++){
      if(get_plateau()[i][j].get_content() == 0){
         cout << "." << "\t";
      }else{
        cout << get_plateau()[i][j].get_content() << "\t";
      }
    }
  }
  cout << endl;
}

// Gives a random position from [0, grid_size_x]
template <typename T>
int Board<T>::rand_posx(){
  return random_integer(get_matrix_length_x() - 1);
}

// Gives a random position from [0, grid_size_y]
template <typename T>
int Board<T>::rand_posy(){
  return  random_integer(get_matrix_length_y() - 1);
}


// Sets the x and y with a random empty position
template <typename T>
void Board<T>::random_empty_pos(int& x, int& y){
    if(!has_empty()){
        return;
    }
    do{
        x = rand_posx();
        y = rand_posy();
    }
    while(!(get_plateau()[x][y] == 0));
}

//Return True if there is an empty Box
template <typename T>
bool Board<T>::has_empty(){
    for(int x = 0; x < get_matrix_length_x(); ++x){
      for(int y = 0; y < get_matrix_length_y(); ++y){
        if(get_plateau()[x][y] == 0){
          return true;
        }
      }
    }
    return false;
}

template <typename T>
bool Board<T>::has_lose(){
  return false;
}
