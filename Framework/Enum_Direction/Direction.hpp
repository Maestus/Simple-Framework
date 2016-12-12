#include <iostream>
#include <type_traits>

enum class Direction{
    HAUT = 1,
    BAS = 2,
    GAUCHE = 3,
    DROITE = 4,
    NOTKNOWN
};

std::ostream& operator<<(std::ostream& os, const Direction& obj){
  if(static_cast<std::underlying_type<Direction>::type>(obj) == 1)
    os << "HAUT";
  else if(static_cast<std::underlying_type<Direction>::type>(obj) == 2)
    os << "BAS";
  else if(static_cast<std::underlying_type<Direction>::type>(obj) == 3)
    os << "GAUCHE";
  else if(static_cast<std::underlying_type<Direction>::type>(obj) == 4)
    os << "DROITE";
  else os << "NOT_KNOWN";
   return os;
}
