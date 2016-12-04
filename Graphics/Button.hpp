#include <SFML/Graphics.hpp>

class Button {
public:
    Button (sf::Image* normal,sf::Image* clicked,std::string,sf::Vector2f location);
    void checkClick (sf::Vector2f);
    void setState(bool);
    void setText(std::string);
    bool getVar();
    sf::Sprite* getSprite();
    sf::String * getText();
private:
    sf::Sprite normal;
    sf::Sprite clicked;
    sf::Sprite* currentSpr;
    sf::String String;
    bool current;
};

Button::Button(sf::Image* normal,sf::Image* clicked,std::string words,sf::Vector2f location) {
    this->normal.setImage(*normal);
    this->clicked.setImage(*clicked);
    this->currentSpr=&this->normal;
    current =false;
    this->normal.setPosition(location);
    this->clicked.setPosition(location);
    String.replace(words);
    String.setPosition(location.x+3,location.y+3);
    String.replace(14);
}
void Button::checkClick (sf::Vector2f mousePos) {
    if (mousePos.x>currentSpr->getPosition().x && mousePos.x<(currentSpr->getPosition().x + currentSpr->getScale().x)) {
        if(mousePos.y>currentSpr->getPosition().y && mousePos.y<(currentSpr->getPosition().y + currentSpr->getScale().y)) {
            setState(!current);
        }
    }
}
void Button::setState(bool which) {
    current = which;
    if (current) {
        currentSpr=&clicked;
        return;
    }
    currentSpr=&normal;
}
void Button::setText(std::string words) {
    String.setText(words);
}
bool Button::getVar() {
    return current;
}
sf::Sprite* Button::getSprite() {
    return currentSpr;
}

sf::String * Button::getText() {
    return &String;
}
