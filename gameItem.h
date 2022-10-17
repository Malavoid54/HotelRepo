#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>
#include <string>

using namespace sf;

class GameEntity {
    protected:
        Sprite* body;
        Texture texture;
        IntRect source;
    public:
        virtual void draw(RenderWindow* win) {
            win->draw(*body);
        }
        virtual bool highlightSprite(Sprite* sprite) = 0;
};


#endif