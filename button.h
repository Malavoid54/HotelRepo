#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>
#include <string>

using namespace sf;

class Button {
    private:
        Sprite* body;
        Texture texture;
        IntRect* source;
        Text title;
        Font font;
    public:
        Button() {
            source = new IntRect(0,0,200,20);
            if (!texture.loadFromFile("./buttons.png")) {
                std::cout <<"Image not Found\n";
                exit(0);
            }
            body = new Sprite();
            body->setTexture(texture);
            body->setTextureRect(*source);
            body->setOrigin(100,10);
            body->setScale(3,3);
            if (!font.loadFromFile("./buttonFont.ttf")) {
                std::cout <<"Font not Found\n";
                exit(0);
            }
            title.setFont(font);
            title.setFillColor(sf::Color::White);
            title.setCharacterSize(30);
            
        }
        void draw(RenderWindow* win) {
            win->draw(*body);
            win->draw(title);
        }
        void setText (std::string text) {
            title.setString(text);
            FloatRect textSize = title.getLocalBounds();
            title.setOrigin(textSize.width/2,textSize.height/2);
        }
        void setPosition(RenderWindow* win, int yPos) {
            body->setPosition((win->getSize().x)/2,(yPos+2)*100);
            title.setPosition((win->getSize().x)/2,((yPos+2)*100)-10);
        }
        bool highlightSprite(Sprite* sprite) {
            if (sprite->getGlobalBounds().intersects(body->getGlobalBounds())) {
                source->top = 20;
                body->setTextureRect(*source);
                return true;
            } else {
                source->top = 0;
                body->setTextureRect(*source);
                return false;
            }           
        }

        ~Button() {}
};


#endif