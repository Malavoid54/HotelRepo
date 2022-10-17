#ifndef CLICKTEST_H
#define CLICKTEST_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "game.h"
#include "cursor.h"
#include "button.h"
#include "gameMenu.h"

using namespace sf;

class ClickTest: public Game {
    private:
        RenderWindow* win;
        Mouse_Cursor* cursor;
        GameMenu* menu;
    public:
        ClickTest(int size1, int size2, std::string title) {
            win = new RenderWindow(VideoMode(size1,size2),title);
            win->setVerticalSyncEnabled(true);
            win->setMouseCursorVisible(false);
            win->setMouseCursorGrabbed(true);
            win->setFramerateLimit(144);
            cursor = new Mouse_Cursor(10, win);
            menu = new GameMenu(win);
        }
        void draw_frame () {
            if (menu->getStatus()) {
                menu->draw(win);
            }
            cursor->draw(win);
            
        }
        void checkCollision () {
            
        }
        void run () {
            while (win->isOpen()) {
                Event e;
                while (win->pollEvent(e)) {
                    if (e.type == Event::KeyPressed) {
                        if (e.key.code == Keyboard::Escape) {
                            win->close();
                        }
                    }
                    menu->buttonPress(cursor, e);
                }
                win->clear();
                cursor->move(win);
                draw_frame();
                win->display();
            }
        }
       
        ~ClickTest() {
            delete cursor;
            delete menu;
        }
};


#endif