#ifndef GAMEENTITY_H
#define GAMEENTITY_H

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
        GameEntity () {
            // loads the button texture
            if (!texture.loadFromFile("./buttons.png")) {
                std::cout <<"Image not Found\n";
                exit(0);
            }
        }
        virtual void draw(RenderWindow* win) {
            win->draw(*body);
        }

        void setSprite(int x, int y) {
            source.top = y;
            source.left = x;
            body->setTextureRect(source);
        }

        virtual void setPosition(RenderWindow* win, int x, int y) = 0;

        bool highlightSprite(Sprite* sprite, int x, int y) {
            if (sprite->getGlobalBounds().intersects(body->getGlobalBounds())) {
                setSprite(x,y+source.height);
                return true;
            } else {
                setSprite(x,y);
                return false;
            }           
        }
        ~GameEntity() {
            delete body;
        }
};


#endif