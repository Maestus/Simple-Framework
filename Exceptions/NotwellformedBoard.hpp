#include <iostream>
#include <exception>
#include <string>

#define BORD "***********************************"

class NotwellformedBoard{
  public:
    NotwellformedBoard(int a,int b):x(a),y(b){}

    virtual const char* what() const throw(){
      std::cout <<  BORD << std::endl;
      return "Plateau de jeu mal formé\n";
    }

    std::string how() const throw(){
      std::string first = "x = ";
      std::string second = "y = ";
      std::string result;
      result = first + std::to_string(x) + "\n" + second + std::to_string(y) + "\n" + BORD;
      return result;
    }
  private:
    int x;
    int y;
};
