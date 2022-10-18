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

// game loop
class ClickTest: public Game {
    private:
        // pointers to the window, cursor and rooms
        RenderWindow* win;
        Mouse_Cursor* cursor;
        GameMenu* menu;
    public:
        // constructor for the game
        ClickTest(int size1, int size2, std::string title) {
            // initialises the window settings
            win = new RenderWindow(VideoMode(size1,size2),title);
            win->setMouseCursorVisible(false);
            win->setMouseCursorGrabbed(true);
            win->setFramerateLimit(60);

            // initialises the rooms and cursor
            cursor = new Mouse_Cursor(win);
            menu = new GameMenu(win);
        }

        // draws all currently active sprites
        void draw_frame () {
            menu->draw(win);
            cursor->draw(win);
            
        }

        // checks for the collision of the cursor with buttons or items
        void checkCollision (Mouse_Cursor*, Event e) {
            menu->buttonPress(cursor, e);
        }

        // runs the program
        void run () {
            while (win->isOpen()) {
                Event e;

                // polls for events
                while (win->pollEvent(e)) {

                    // code to quit the game if 'Esc' is pressed
                    if (e.type == Event::KeyPressed) {
                        if (e.key.code == Keyboard::Escape) {
                            win->close();
                        }
                    }
                    checkCollision(cursor, e);
                }

                // makes sure everything is being drawn
                win->clear();
                cursor->move(win);
                draw_frame();
                win->display();
            }
        }

        // deletes any pointers
        ~ClickTest() {
            delete cursor;
            delete menu;
        }
};


#endif