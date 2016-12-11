template <class T>
Board<T>::Board(): score(), matrix_length_x(), matrix_length_y(), plateau(){};

template <class T>
Board<T>::Board(int a, int b): score(), matrix_length_x(a), matrix_length_y(b), plateau(matrix_length_x,vector<Box<T>>(matrix_length_y)){
  if(a <= 1 || b <= 1){
    throw NotwellformedBoard(matrix_length_x,matrix_length_y);
  }
}

template <typename T>
int Board<T>::random_integer(int n){
  // Seed with a real random value, if available
  random_device r;
  // Choose a random mean between 1 and 6
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
void Board<T>::print(){
  for(int i = 0; i < matrix_length_x; i++){
    if(i>0)
      cout << endl;
    for(int j = 0; j < matrix_length_y; j++)
      if(plateau[i][j] == 0)
        cout << "  .  ";
      else
        cout << "  " << plateau[i][j] << "  ";
  }
  cout << endl;
}

template <typename T>
std::vector <std::vector<Box<T>>>& Board<T>::get_plateau(){
  return this->plateau;
}
