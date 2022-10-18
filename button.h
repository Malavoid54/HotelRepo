#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>
#include <string>
#include "gameItem.h"

using namespace sf;

// class for the three main menu buttons
class Button: public GameEntity {
    private:
        // determines the text for the buttons
        Text title;
        Font font;
    public:
        // constructor, with set sizes for each button
        Button() {
            // determines the size of each button
            source.height = 20;
            source.width = 200;
            
            // loads the button texture
            if (!texture.loadFromFile("./buttons.png")) {
                std::cout <<"Image not Found\n";
                exit(0);
            }

            // creates the sprite and sets the scale
            body = new Sprite();
            body->setTexture(texture);
            body->setTextureRect(source);
            body->setOrigin(100,10);
            body->setScale(3,3);

            // loads the font for the buttons
            if (!font.loadFromFile("./buttonFont.ttf")) {
                std::cout <<"Font not Found\n";
                exit(0);
            }

            // initialises the font size and colour
            title.setFont(font);
            title.setFillColor(sf::Color::White);
            title.setCharacterSize(30);
            
        }

        // draws the buttons 
        void draw(RenderWindow* win) {
            win->draw(*body);
            win->draw(title);
        }

        // determines what is written on the buttons
        void setText (std::string text) {
            title.setString(text);
            
            // makes sure the text's 'hitbox' is centred 
            FloatRect textSize = title.getLocalBounds();
            title.setOrigin(textSize.width/2,textSize.height/2);
        }

        // sets the position of the text and button
        void setPosition(RenderWindow* win, int x, int y) {
            x = (win->getSize().x)/2;
            body->setPosition(x,(y+3)*100);
            title.setPosition(x,((y+3)*100)-10);
        }

        // renders different textures based on if the cursor is hovering over the sprite
        bool highlightSprite(Sprite* sprite) {
            if (sprite->getGlobalBounds().intersects(body->getGlobalBounds())) {
                setTexture(0,20);
                return true;
            } else {
                setTexture(0,0);
                return false;
            }           
        }
        ~Button() {}
};


#endif