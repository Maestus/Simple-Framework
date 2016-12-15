#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "2048_Module/Classic/Playclassic.hpp"

using namespace std;

Playclassic classic(10,10);
sf::Font font;
sf::Color windowBGColour(250, 248, 239, 255);
sf::Color gridBGColour(187, 173, 160, 255);
sf::Color menuBGColour(187, 173, 255, 255);
sf::Color textColour(67, 53, 40, 255);

float padding = 10.f;
float gridSize = (400.f - (padding * 2.f));
float tileSize = (gridSize - (5 * 45.f)) / 4;

sf::RenderWindow renderWindow(sf::VideoMode(800, 640), "Simple Framework", sf::Style::Close|sf::Style::Titlebar);
sf::RectangleShape BackgroundRect2048(sf::Vector2f(gridSize, gridSize));
sf::RectangleShape gameOverBackground(sf::Vector2f(gridSize, gridSize));
sf::RectangleShape gridTile(sf::Vector2f(tileSize, tileSize));
sf::Text titleText("2048!", font, 48);
sf::Text gameOverText("Game Over!", font, 50);
sf::Text scoreText(to_string(classic.get_score()),font, 48);
sf::Text scoreDecoratorText("", font, 15);
sf::Text tileText;

bool showGameOver = false;

void rendergame(){
  renderWindow.clear(windowBGColour);

  for (int ix = 0; ix < classic.get_matrix_length_x(); ix++) {
    for (int iy = 0; iy < classic.get_matrix_length_y(); iy++) {
      gridTile.setPosition(sf::Vector2f(20 + (ix * (tileSize + padding)), 120 + (iy * (tileSize + padding))));
      gridTile.setFillColor(sf::Color::Black);
      renderWindow.draw(gridTile);

      if (classic.get_plateau()[iy][ix] > 0) {
        tileText.setString(to_string(classic.get_plateau()[iy][ix]));
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
	scoreText.setString(to_string(classic.get_score()));
	scoreText.setPosition(sf::Vector2f(380 - scoreText.getGlobalBounds().width, 25));
	renderWindow.draw(scoreText);
	scoreDecoratorText.setString("score:");
	scoreDecoratorText.setPosition(sf::Vector2f(scoreText.getPosition().x - scoreDecoratorText.getGlobalBounds().width - 10, 57));
	renderWindow.draw(scoreDecoratorText);

	// Handle game over display
	if (showGameOver) {
		renderWindow.draw(gameOverBackground);
		renderWindow.draw(gameOverText);
		scoreDecoratorText.setString("Hit enter to restart");
		scoreDecoratorText.setPosition(sf::Vector2f(gameOverText.getPosition().x + 75, gameOverText.getPosition().y + gameOverText.getLocalBounds().height + padding*2));
		renderWindow.draw(scoreDecoratorText);
	}

	renderWindow.draw(titleText);
	renderWindow.display();
}




int main(int argc, char ** argv){

  // Set up the background menu for 2048 games
  BackgroundRect2048.setFillColor(menuBGColour);
  BackgroundRect2048.setPosition(sf::Vector2f(10, 110));

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

  sf::Texture texture;
  if (!font.loadFromFile("ressources/font/ClearSans-Bold.ttf")) {
		printf("Font fail\r\n");
		return 1;
	}
  if (!texture.loadFromFile("ressources/img/2048.png")){
    cerr << "Make sure you have the rights in the folder !" << endl;
    exit(1);
  }
  sf::Sprite sprite(texture);
  sprite.setPosition(sf::Vector2f(170, 200)); // position absolue
  sf::FloatRect rect = sprite.getGlobalBounds();

  string str;
  sf::Text text;

  bool choice_made = false;
  bool dimension_choose = false;
  bool scheduledNumberAdd = false;
  sf::Clock clock;
  clock.restart();
  sf::Time addTimeout = sf::milliseconds(75);

  classic.init();
  while (renderWindow.isOpen()){

    sf::Event event;
    while (renderWindow.pollEvent(event)){

      if (event.type == sf::Event::EventType::Closed){
        renderWindow.close();
      }else if(event.type == sf::Event::MouseButtonPressed && !choice_made){
        if (event.mouseButton.button == sf::Mouse::Left){
          if(event.mouseButton.x <= rect.width+rect.left && event.mouseButton.x >= rect.left
            && event.mouseButton.y <= rect.height+rect.top && event.mouseButton.y >= rect.top ){
            choice_made = true;
          }
        }
      }if (event.type == sf::Event::TextEntered && !dimension_choose){
        if (event.text.unicode < 128){
          str += static_cast<char>(event.text.unicode);
          text.setString(str);
        }
      }else if (event.type == sf::Event::KeyPressed && !scheduledNumberAdd && choice_made) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				  classic.apply_move(Direction::HAUT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
          classic.apply_move(Direction::DROITE);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
          classic.apply_move(Direction::BAS);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
          classic.apply_move(Direction::GAUCHE);
				}
			}
    }

    if (scheduledNumberAdd && clock.getElapsedTime() > addTimeout) {
      scheduledNumberAdd = false;
    }

    renderWindow.clear(sf::Color(255, 255, 255));
    if(!choice_made){
      renderWindow.draw(BackgroundRect2048);
      renderWindow.draw(sprite);
    }
    else
      rendergame();
    renderWindow.display();
  }
}
