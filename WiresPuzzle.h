#ifndef WIRESPUZZLE_H
#define WIRESPUZZLE_H

#include "room.h"
#include "roomArrow.h"
#include "cursor.h"
#include "gameMenu.h"
#include "gameItem.h"

// first room puzzle
class WiresPuzzle: public Room {
    private:
        RenderWindow* store;
        RoomArrow* buttons;
        GameItem* options;
        bool mainWall;
        int nOptions;
    public:
        // constructor
        WiresPuzzle (RenderWindow* win) {
            // initialises room settings
            setRoom(480,270);
            active = false;
            store = win;

            // creates the clickable buttons
            nOptions = 3;
            options = new GameItem[nOptions];
            for (int i = 0; i < nOptions; i++) {
                options[i].createSprite(9,6,6);
            }

            // positions the 3 options
            options[0].setPosition(win,700,850);
            options[1].setPosition(win,950,800);
            options[2].setPosition(win,1130,830);
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
            if (options[0].highlightSprite(cursor->getSprite(),117,40) && active) {
                if (e.type == Event::MouseButtonPressed) {
                    // close game if wrong
                    if (e.mouseButton.button == Mouse::Left) {
                        store->close();
                    }
                }
            } else if (options[1].highlightSprite(cursor->getSprite(),117,40) && active) {
                if (e.type == Event::MouseButtonPressed) {
                    // close game if wrong
                    if (e.mouseButton.button == Mouse::Left) {
                        store->close();
                    }
                }
            } else if (options[2].highlightSprite(cursor->getSprite(),117,40) && active) {
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

        ~WiresPuzzle() {
            delete [] buttons;
            delete [] options;
        }
};

#endif