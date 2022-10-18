#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>
#include <string>

using namespace sf;

// base room class for each room to be constructed
class Room{
    protected:
        // variables needed to create the background
        Texture backTexture;
        Sprite* background;
        IntRect source;

        // bool to check if active
        bool active;
    public:
        // constructor, sets up the initial background to be the menu
        Room() {
            // sets the default size of the background
            source.width = 160;
            source.height = 90;

            // reads the file that holds all background images
            if(!backTexture.loadFromFile("./rooms.png")) {
                std::cout<<"Couldnt load image"<<std::endl;
                exit(0);
            }

            // creates the sprite
            background = new Sprite();
            background->setTexture(backTexture);
            background->setTextureRect(source);
            background->setScale(10,10); // scales up the room texture

            // initially sets the room to inactive
            active = false;
            
        }

        // function that allows for switching background images
        void setRoom (int x, int y) {
            source.top = y;
            source.left = x;
            background->setTextureRect(source);
        }

        // checks if a room is active or not
        virtual bool getStatus () {
            return active;
        }

        // sets as active
        void setActive () {
            active = true;
        }

        // function for each room to draw to window
        virtual void draw(RenderWindow* win) {};

        // handles pressing items and buttons
        virtual void buttonPress(Mouse_Cursor* cursor, Event e) {};

        // destructor
        ~Room () {
            delete background;
        }
};
#endif
