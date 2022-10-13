#ifndef CLICKTEST_H
#define CLICKTEST_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "game.h"
#include "cursor.h"
#include "button.h"

using namespace sf;

class ClickTest: public Game {
    private:
        RenderWindow* win;
        Mouse_Cursor* cursor;
        Button* button;
    public:
        ClickTest(int size1, int size2, std::string title) {
            win = new RenderWindow(VideoMode(size1,size2),title);
            win->setMouseCursorVisible(false);
            win->setMouseCursorGrabbed(false);
            cursor = new Mouse_Cursor(10, win);
            button = new Button(win);
        }
        void draw_frame () {
            button->draw(win);
            cursor->draw(win);
            
            
        }
        void checkCollision() {
            button->highlightSprite(cursor->getSprite());
        }
        void run () {
            while (win->isOpen()) {
                Event e;
                while (win->pollEvent(e)) {
                    cursor->move(win);
                    if (e.type == Event::KeyPressed) {
                        if (e.key.code == Keyboard::Escape) {
                            win->close();
                        }
                    }
                }
                win->clear();
                checkCollision();
                draw_frame();
                win->display();
            }
        }
        ~ClickTest() {
            delete cursor;
            delete button;
        }
};


#endif