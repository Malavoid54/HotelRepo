#ifndef CLICKTEST_H
#define CLICKTEST_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "game.h"
#include "cursor.h"

using namespace sf;

class ClickTest: public Game {
    private:
        RenderWindow* win;
        Mouse_Cursor* cursor;
        bool isFocused;
    public:
        ClickTest(int size, std::string title) {
            isFocused = true;
            win = new RenderWindow(VideoMode(size,size),title);
            win->setMouseCursorVisible(false);
            win->setMouseCursorGrabbed(isFocused);
            cursor = new Mouse_Cursor(10, win);
        }
        void draw_frame () {
            cursor->draw(win);
        }
        void run () {
            while (win->isOpen()) {
                Event e;
                while (win->pollEvent(e)) {
                    cursor->move(win);
                    if (e.type == Event::Closed) {
                        win->close();
                    } 
                    if (e.type == Event::KeyPressed) {
                        if (e.key.code == Keyboard::Escape) {
                            win->close();
                        }
                    }
                }
                win->clear();
                draw_frame();
                win->display();
            }
        }
        ~ClickTest() {}
};


#endif