#ifndef PYRAMIDPUZZLE_H
#define PYRAMIDPUZZLE_H

#include "room.h"
#include "roomArrow.h"
#include "cursor.h"
#include "gameMenu.h"
#include "gameItem.h"

// first room puzzle
class PyramidPuzzle: public Room {
    private:
        RenderWindow* store;
        RoomArrow* buttons;
        GameItem* options;
        bool mainWall;
        int nOptions;
    public:
        // constructor
        PyramidPuzzle(RenderWindow* win) {
            // initialises room settings
            setRoom(480,0);
            active = false;
            store = win;
            
            // creates the clickable buttons
            nOptions = 3;
            options = new GameItem[nOptions];
            for (int i = 0; i < nOptions; i++) {
                options[i].createSprite(13,14,6);
            }

            // positions the 3 options
            options[0].setPosition(win,1400,80);
            options[1].setPosition(win,1400,250);
            options[2].setPosition(win,1400,420);
        }

        // draws the room and items
        void draw(RenderWindow* win) {
            if (active) {
                // draws background
                win->draw(*background);
                for (int i = 0; i < nOptions; i++) {
                        options[i].draw(win);
                    }
            }
        }
        
        // handles button presses
        void buttonPress(Mouse_Cursor* cursor, Event e) {
            if (options[0].highlightSprite(cursor->getSprite(),126,40) && active) {
                if (e.type == Event::MouseButtonPressed) {
                    // close game if wrong
                    if (e.mouseButton.button == Mouse::Left) {
                        store->close();
                    }
                }
            } else if (options[1].highlightSprite(cursor->getSprite(),139,40) && active) {
                if (e.type == Event::MouseButtonPressed) {
                    // close game if wrong
                    if (e.mouseButton.button == Mouse::Left) {
                        store->close();
                    }
                }
            } else if (options[2].highlightSprite(cursor->getSprite(),152,40) && active) {
                if (e.type == Event::MouseButtonPressed) {
                    // correct answer
                    if (e.mouseButton.button == Mouse::Left) {
                        active = false;
                    }
                }
            }
        }
        
        // returns the state of the room
        bool getStatus() {
            return active;
        }

        ~PyramidPuzzle() {
            delete [] buttons;
            delete [] options;
        }
};

#endif