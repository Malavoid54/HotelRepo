#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>
#include <string>

using namespace sf;

class Room{
    protected:
        Texture backTexture;
        Sprite* background;
        IntRect source;
        bool active;
    public:
        Room() {
            source.width = 160;
            source.height = 90;
            if(!backTexture.loadFromFile("./rooms.png")) {
                std::cout<<"Couldnt load image"<<std::endl;
                exit(0);
            }
            background = new Sprite();
            background->setTexture(backTexture);
            background->setTextureRect(source);
            background->setScale(10,10);
            
        }
        void setRoom (int x, int y) {
            source.top = y;
            source.left = x;
            background->setTextureRect(source);
        }

        bool getStatus () {
            return active;
        }

        virtual void draw(RenderWindow* win) {
            win->draw(*background);
        }
};
#endif
