/******************************************************************************
                  Interface à implémenter dans chaque Jeu
******************************************************************************/

#include "Board.hpp"

template <typename T>
class Game{
public:
  virtual bool setValue() = 0;
  virtual bool victory(const Board<T> &) = 0;
  virtual bool oneMove(T) = 0;
};
