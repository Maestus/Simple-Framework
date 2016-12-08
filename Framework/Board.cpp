template <class T>
Board<T>::Board():matrix_length_x(), matrix_length_y(), plateau(){};

template <class T>
Board<T>::Board(int a, int b): matrix_length_x(a), matrix_length_y(b), plateau(matrix_length_x,vector<Box<T>>(matrix_length_y)){
  if(a <= 1 || b <= 1){
    throw NotwellformedBoard(matrix_length_x,matrix_length_y);
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
void Board<T>::print(){
  for(int i = 0; i < matrix_length_x; i++){
    if(i>0)
      cout << endl;
    for(int j = 0; j < matrix_length_y; j++)
      if(plateau[i][j] == 0)
        cout << ".";
      else
        cout << plateau[i][j];
  }
  cout << endl;
}

template <typename T>
std::vector <std::vector<Box<T>>>& Board<T>::get_plateau(){
  return this->plateau;
}
