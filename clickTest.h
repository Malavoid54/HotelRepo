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
            win->setMouseCursorGrabbed(true);
            cursor = new Mouse_Cursor(10, win);
            button = new Button[3];
            for (int i = 0; i < 3; i++) {
                button[i].setPosition(win,(3-i));
            }
            button[2].setText("Start Game");
            button[1].setText("Load Game");
            button[0].setText("Quit Game");
        }
        void draw_frame () {
            for (int i = 0; i < 3; i++){
                button[i].draw(win);
            }
            cursor->draw(win);
            
            
        }
        void checkCollision() {
            for (int i = 0; i < 3; i++){
                button[i].highlightSprite(cursor->getSprite());
            }
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
                    if (e.type == Event::MouseButtonPressed) {
                        if (e.mouseButton.button == Mouse::Left) {
                            if (button[0].highlightSprite(cursor->getSprite())) {
                                win->close();
                            }
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
            delete [] button;
        }
};


#endif