#ifndef CURSOR_H
#define CURSOR_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Mouse_Cursor {
    private:
        Sprite* body;
        Vector2i position;
        Texture texture;
        Sprite* collision;
    public:
        Mouse_Cursor(int r, RenderWindow* win) {
            position = Mouse::getPosition(*win);
            if (!texture.loadFromFile("./cursor.png", IntRect(0,0,26,26))) {
                std::cout <<"Image not Found\n";
                exit(0);
            }
            body = new Sprite(texture);
            collision = new Sprite();
            collision->setTextureRect(IntRect(0,0,1,1));
            body->setPosition(position.x,position.y);
            collision->setPosition(position.x,position.y);
            body->setOrigin(0,0);
            
        }
        void draw(RenderWindow* win) {
            win->draw(*body);
        }
        void move(RenderWindow* win) {
            position = Mouse::getPosition(*win);
            body->setPosition(position.x,position.y);
            collision->setPosition(position.x,position.y);
        }
        Sprite* getSprite () {
            return collision;
        }
        ~Mouse_Cursor() {delete this->body;}
};

#endif