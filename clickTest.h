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
#include "LightsPuzzle.h"
#include "Cubespuzzle.h"

using namespace sf;

// game loop
class ClickTest: public Game {
    private:
        // pointers to the window, cursor and rooms
        RenderWindow* win;
        Mouse_Cursor* cursor;
        Room** rooms;
        int roomCount;
        int *currentRoom;
    public:
        // constructor for the game
        ClickTest(int size1, int size2, std::string title) {
            // initialises the window settings
            win = new RenderWindow(VideoMode(size1,size2),title);
            win->setMouseCursorVisible(false);
            win->setMouseCursorGrabbed(true);
            win->setFramerateLimit(60);
            
            // keeps track of the current room
            currentRoom = new int;
            *currentRoom = 0;

            // initialises the rooms and cursor
            roomCount = 4;
            rooms = new Room*[roomCount];
            rooms[0] = new GameMenu(win);
            rooms[1] = new ChessPuzzle(win);
            rooms[2] = new LightsPuzzle(win);
            rooms[3] = new CubesPuzzle(win);
            cursor = new Mouse_Cursor(win);
        }

        // draws all currently active sprites
        void drawFrame () {
            rooms[*currentRoom]->draw(win);
            cursor->draw(win);          
        }

        void checkActive () {
            // checks if the menu is active
            if (rooms[0]->getStatus()) {
                std::cout << *currentRoom << std::endl;

            // checks if the menu is inactive and the current room is the menu, then sets the next active
            } else if (*currentRoom == 0 && !rooms[0]->getStatus()) {
                rooms[1]->setActive();
                *currentRoom = 1;
                std::cout << *currentRoom << std::endl;

            // checks if the first room is inactive and the current room is the first, then sets the next active
            } else if (*currentRoom == 1 && !rooms[1]->getStatus()) {
                rooms[2]->setActive();
                *currentRoom = 2;
                std::cout << *currentRoom << std::endl;

            
            } else if (*currentRoom == 2 && !rooms[2]->getStatus()) {
                rooms[3]->setActive();
                *currentRoom = 3;
                std::cout << *currentRoom << std::endl;
            }
            
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
                checkActive();
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