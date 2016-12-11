#include "../Framework/Board.hpp"

class Taquin : public Board<int>{
public:
  Taquin(int,int);
  int getGridSize() ;
  bool has_empty();
  int rand_pos();
  void random_empty_pos(int&, int&);
  virtual void init(int) = 0;
  virtual void add_value() = 0;
  bool apply_move(Direction);
  virtual void merge_tiles(Direction) = 0;
  int random_integer(int);
  Board<int> grid;
};
