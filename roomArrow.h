#ifndef ROOMARROW_H
#define ROOMARROW_H

#include "button.h"

class RoomArrow: public Button {
    public:
        RoomArrow() {
            // determines the size of each button
            source.height = 20;
            source.width = 11;
            
            // creates the sprite and sets the scale
            body = new Sprite();
            body->setTexture(texture);
            body->setTextureRect(source);
            setSprite(200,0);
            body->setOrigin(6,10);
            body->setScale(9,9);
        }
        
        // sets the position of the text and button
        void setPosition(RenderWindow* win, int x, int y) {
            body->setPosition(x,(win->getSize().y)/2);
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