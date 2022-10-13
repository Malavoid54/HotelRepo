#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>

using namespace sf;

class Button {
    private:
        Sprite* body;
        Texture texture;
        IntRect* source;
    public:
        Button(RenderWindow* win) {
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
            body->setPosition((win->getSize().x)/2,(win->getSize().y)-400);
            
        }
        void draw(RenderWindow* win) {
            win->draw(*body);
        }
        void highlightSprite(Sprite* sprite) {
            if (sprite->getGlobalBounds().intersects(body->getGlobalBounds())) {
                source->top = 20;
                body->setTextureRect(*source);
            } else {
                source->top = 0;
                body->setTextureRect(*source);
            }           
        }

        ~Button() {}
};


#endif