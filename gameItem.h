#ifndef GAMEITEM_H
#define GAMEITEM_H

#include "gameEntity.h"

class GameItem: public GameEntity {
    private:
        bool pressed;
    public:
        GameItem () {}
        void createSprite(int x, int y, int scale) {
            // determines the size of each button
            source.height = x;
            source.width = y;
            
            // creates the sprite and sets the scale
            body = new Sprite();
            body->setTexture(texture);
            body->setTextureRect(source);
            body->setScale(scale,scale);
        }
        
        // sets the position of the text and button
        void setPosition(RenderWindow* win, int x, int y) {
            body->setPosition(x,y);
        }

        // draws the button
        void draw (RenderWindow* win) {
            win->draw(*body);
        }

        // flips the button
        void flipButton() {
            body->setScale(-9,9);
        }
};

#endif
