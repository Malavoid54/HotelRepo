#ifndef CURSOR_H
#define CURSOR_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

// class for the mouse cursor
class Mouse_Cursor {
    private:
        // variables needed for the sprite
        Sprite* body;
        Texture texture;
        Sprite* collision;
        Vector2i position;
    public:
        // constructor to create the cursor
        Mouse_Cursor(RenderWindow* win) {
            // sets the position to follow the mouse
            position = Mouse::getPosition(*win);

            // loads the cursor image file
            if (!texture.loadFromFile("./cursor.png", IntRect(0,0,26,26))) {
                std::cout <<"Image not Found\n";
                exit(0);
            }

            // creates the sprite for the cursor, and one for collision 
            body = new Sprite(texture);
            collision = new Sprite();
            collision->setTextureRect(IntRect(0,0,1,1)); // collision sprite is smaller to ensure correct use of mouse
            body->setPosition(position.x,position.y);
            collision->setPosition(position.x,position.y);
            body->setOrigin(0,0); // origin of cursor is set to the centre of the original cursor
            
        }

        // renders the cursor
        void draw(RenderWindow* win) {
            win->draw(*body);
        }

        // moves the cursor to follow the mouse
        void move(RenderWindow* win) {
            position = Mouse::getPosition(*win);
            body->setPosition(position.x,position.y);
            collision->setPosition(position.x,position.y);
        }

        // returns the collision sprite, used for collision detection
        Sprite* getSprite () {
            return collision;
        }

        // destructor
        ~Mouse_Cursor() {delete this->body;}
};

#endif