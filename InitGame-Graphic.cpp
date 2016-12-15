#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "2048_Module/Classic/Playclassic.hpp"

using namespace std;

int main(int argc, char ** argv){
  sf::Font font;
  Playclassic classic(4,4);
  float padding = 10.f;
  float gridSize = (640.f - (padding * 2.f));
  float tileSize = (gridSize - (5 * padding)) / 4;
  sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Simple_Framework");
  sf::RectangleShape gridTile(sf::Vector2f(tileSize, tileSize));
  sf::Text scoreText(to_string(classic.get_score()),font, 48);
  sf::Text scoreDecoratorText("", font,15);
  sf::Event event;
  sf::Texture texture;
  if (!font.loadFromFile("ClearSans-Bold.ttf")) {
		printf("Font fail\r\n");
		return 1;
	}
  if (!texture.loadFromFile("img/2048.png")){
    cerr << "Make sure you have the rights in the folder !" << endl;
    exit(1);
  }
  bool choice_made = false;
  sf::Sprite sprite(texture);
  sprite.setPosition(sf::Vector2f(290, 210)); // position absolue
  sf::FloatRect rect = sprite.getGlobalBounds();
  cout << rect.left << endl;
  while (renderWindow.isOpen()&& !choice_made){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed){
        renderWindow.close();
      }else if(event.type == sf::Event::MouseButtonPressed){
        if (event.mouseButton.button == sf::Mouse::Left){
          if(event.mouseButton.x <= rect.width+rect.left && event.mouseButton.x >= rect.left
            && event.mouseButton.y <= rect.height+rect.top && event.mouseButton.y >= rect.top ){
            std::cout << "the right button was pressed" << std::endl;
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            choice_made = true;
          }
        }
      }
    }
    renderWindow.clear(sf::Color(52, 92, 142));
    renderWindow.draw(sprite);
    renderWindow.display();
  }
}
