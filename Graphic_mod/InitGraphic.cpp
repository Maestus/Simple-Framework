using namespace std;
#include "InitGraphic.hpp"


sf::Color windowBGColour(250, 248, 239, 255);
 sf::Color gridBGColour(187, 173, 160, 255);
 sf::Color menuBGColour(187, 173, 255, 255);
 sf::Color textColour(67, 53, 40, 255);

template <typename T>
InitGraphic<T>::InitGraphic(T *a):instance(a){

  if (!font.loadFromFile("/home/rached/C++/Simple-Framework/Graphic_mod/ressources/font/ClearSans-Bold.ttf")) {
    printf("Font fail\r\n");
    exit(1);
  }
  renderWindow.create(sf::VideoMode(1024, 700), "Simple Framework", sf::Style::Close|sf::Style::Titlebar);

  //Due to Hard CPU use, adding a limitation of FPS
  renderWindow.setFramerateLimit(60);

  // Set up the title text
  titleText.setStyle(sf::Text::Bold);
  titleText.setFillColor(textColour);
  titleText.setPosition(sf::Vector2f(10, 25));

  // Set up the score text objects
  scoreText.setStyle(sf::Text::Bold);
  scoreText.setFillColor(textColour);
  scoreDecoratorText.setFillColor(textColour);

  // Set up the tile text
  tileText.setFont(font);
  tileText.setCharacterSize(32);
  tileText.setStyle(sf::Text::Bold);

  gridTile.setSize(sf::Vector2f(tileSize, tileSize));

  titleText.setString("Framework Graphic Demo");
  titleText.setFont(font);
  titleText.setCharacterSize(25);

  gameOverText.setString("Game Over!");
  gameOverText.setFillColor(textColour);
  gameOverText.setFont(font);
  gameOverText.setCharacterSize(25);
  gameOverText.setStyle(sf::Text::Bold);

  winText.setString("You Win!");
  winText.setFillColor(textColour);
  winText.setFont(font);
  winText.setCharacterSize(25);
  winText.setStyle(sf::Text::Bold);

  scoreText.setString(to_string(instance->get_score()));
  scoreText.setFont(font);
  scoreText.setCharacterSize(25);
  scoreDecoratorText.setFont(font);
  scoreDecoratorText.setCharacterSize(25);
  scoreDecoratorText.setString("score:");
	scoreDecoratorText.setPosition(sf::Vector2f(titleText.getPosition().x + titleText.getGlobalBounds().width + 100, titleText.getPosition().y));
  showGameOver = false;
  showWin = false;

}


template <typename T>
void InitGraphic<T>::rendergame(){
  renderWindow.clear(windowBGColour);

  for (int ix = 0; ix < instance->get_matrix_length_x(); ix++) {
    for (int iy = 0; iy < instance->get_matrix_length_y(); iy++) {
      gridTile.setPosition(sf::Vector2f(20 + (iy * (tileSize + padding)),100 + (ix * (tileSize + padding))));
      gridTile.setFillColor(sf::Color::Black);
      renderWindow.draw(gridTile);

      if (instance->get_plateau()[ix][iy] > 0 || instance->get_plateau()[ix][iy] < 0) {
        tileText.setString(to_string(instance->get_plateau()[ix][iy]));
        tileText.setCharacterSize(14);
        sf::Vector2f textPosition = (gridTile.getPosition() + (gridTile.getSize() / 2.f));
        textPosition.x -= tileText.getGlobalBounds().width / 2.f;
        textPosition.y -= (tileText.getGlobalBounds().height + padding) / 2.f;
        tileText.setPosition(textPosition);
        renderWindow.draw(tileText);
      }
    }
  }
  // render the score info
	scoreText.setString(to_string(instance->get_score()));
	scoreText.setPosition(sf::Vector2f(scoreDecoratorText.getGlobalBounds().width + scoreDecoratorText.getPosition().x + 10 , titleText.getPosition().y));
	renderWindow.draw(scoreText);

	renderWindow.draw(scoreDecoratorText);

	// Handle game over display
	if (showGameOver) {
    gameOverText.setPosition(sf::Vector2f(scoreText.getPosition().x + scoreText.getGlobalBounds().width + 100, titleText.getPosition().y));
		renderWindow.draw(gameOverText);
	}else if(showWin){
    winText.setPosition(sf::Vector2f(scoreText.getPosition().x + scoreText.getGlobalBounds().width + 100, titleText.getPosition().y));
    renderWindow.draw(winText);
  }

	renderWindow.draw(titleText);
	renderWindow.display();
}

template <typename T>
void InitGraphic<T>::init_graphic_mode(){

  string str;
  sf::Text text;
  bool scheduledNumberAdd = false;
  sf::Clock clock;
  clock.restart();
  sf::Time addTimeout = sf::milliseconds(75);

  while (renderWindow.isOpen()){
    sf::Event event;
    while (renderWindow.pollEvent(event)){

      if (event.type == sf::Event::EventType::Closed){
        renderWindow.close();
      }
      else if (event.type == sf::Event::KeyPressed && !scheduledNumberAdd) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				  instance->apply_move(Direction::HAUT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
          instance->apply_move(Direction::DROITE);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
          instance->apply_move(Direction::BAS);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
          instance->apply_move(Direction::GAUCHE);
				}
			}
    }

    renderWindow.clear(sf::Color(255, 255, 255));

    if(instance->has_lose()){
      showGameOver = true;
    }else if(instance->has_win()){
      showWin = true;
    }



    if (scheduledNumberAdd && clock.getElapsedTime() > addTimeout) {
      scheduledNumberAdd = false;
    } else {
      rendergame();
    }
    renderWindow.display();
  }
}
