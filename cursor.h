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
    public:
        Mouse_Cursor(int r, RenderWindow* win) {
            position = Mouse::getPosition(*win);
            if (!texture.loadFromFile("./cursor.png", IntRect(0,0,26,26))) {
                std::cout <<"Image not Found\n";
                exit(0);
            }
            body = new Sprite();
            body->setTexture(texture);
            body->setPosition(position.x,position.y);
            body->setOrigin(7,7);
        }
        void draw(RenderWindow* win) {
            win->draw(*body);
        }
        void move(RenderWindow* win) {
            position = Mouse::getPosition(*win);
            body->setPosition(position.x,position.y);
        }
};

#endif