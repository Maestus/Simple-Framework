#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
template <typename T>
class InitGraphic {
public:
  InitGraphic() = delete;
  InitGraphic(T *a);
  void init_graphic_mode();
  void rendergame();
private:
  T *instance;
  float padding = 10.f;
  float gridSize = (400.f - (padding * 2.f));
  float tileSize = (gridSize - (5 * 45.f)) / 3.75;
  sf::Font font;
  sf::RenderWindow renderWindow;
  sf::Text scoreDecoratorText;
  sf::Text scoreText;
  sf::RectangleShape gameOverBackground;
  sf::RectangleShape gridTile;
  sf::Text titleText;
  sf::Text tileText;
  sf::Text gameOverText, winText;
  bool showGameOver, showWin;
};
#include "InitGraphic.cpp"
