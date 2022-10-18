#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>
#include <string>

using namespace sf;

// base class for game entities
class GameEntity {
    protected:
        Sprite* body;
        Texture texture;
        IntRect source;
    public:
        virtual void draw(RenderWindow* win) {
            win->draw(*body);
        }

        void setTexture(int x, int y) {
            source.top = y;
            source.left = x;
            body->setTextureRect(source);
        }

        virtual void setPosition(RenderWindow* win, int x, int y) = 0;

        virtual bool highlightSprite(Sprite* sprite) = 0;
        ~GameEntity() {
            delete body;
        }
};


#endif