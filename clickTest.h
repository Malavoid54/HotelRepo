#ifndef CLICKTEST_H
#define CLICKTEST_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "game.h"
#include "cursor.h"
#include "button.h"
#include "gameMenu.h"
#include "ChessPuzzle.h"

using namespace sf;

// game loop
class ClickTest: public Game {
    private:
        // pointers to the window, cursor and rooms
        RenderWindow* win;
        Mouse_Cursor* cursor;
        Room** rooms;
        int roomCount;
    public:
        // constructor for the game
        ClickTest(int size1, int size2, std::string title) {
            // initialises the window settings
            win = new RenderWindow(VideoMode(size1,size2),title);
            win->setMouseCursorVisible(false);
            win->setMouseCursorGrabbed(true);
            win->setFramerateLimit(60);

            // initialises the rooms and cursor
            roomCount = 2;
            rooms = new Room*[roomCount];
            rooms[0] = new GameMenu(win);
            rooms[1] = new ChessPuzzle(win);
            cursor = new Mouse_Cursor(win);
        }

        // draws all currently active sprites
        void drawFrame () {
            rooms[checkActive()]->draw(win);
            cursor->draw(win);
            
        }

        int checkActive () {
            for (int i = 0; i < roomCount; i++) {
                if (rooms[i]->getStatus()) {
                    std::cout << "active room " << i << std::endl;
                    return i;
                } else if (!rooms[i]->getStatus()) {
                    rooms[i+1]->setActive();
                    std::cout << "active room " << i+1 << std::endl;
                    return i+1;
                }
            }
            return 0;
        }

        // checks for the collision of the cursor with buttons or items
        void checkCollision (Mouse_Cursor*, Event e) {
            for (int i = 0; i < roomCount; i++) {
                rooms[i]->buttonPress(cursor, e);
            }
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
                drawFrame();
                win->display();
            }
        }

        // deletes any pointers
        ~ClickTest() {
            delete cursor;
            for (int i = 0; i < 2; i++) {
                delete rooms[i];
            } delete [] rooms;
        }
};


#endif