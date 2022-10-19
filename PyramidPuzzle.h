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
        RoomArrow* buttons;
        GameItem* options;
        bool mainWall;
        int nOptions;
    public:
        // constructor
        WiresPuzzle(RenderWindow* win) {
            // initialises room settings
            setRoom(480,0);
            active = false;
            //mainWall = true;
            
            // creates the clickable buttons
            nOptions = 3;
            options = new GameItem[nOptions];
            for (int i = 0; i < nOptions; i++) {
                options[i].createSprite(11,12,6);
            }

            // positions the 3 options
            options[0].setPosition(win,620,80);
            options[1].setPosition(win,620,250);
            options[2].setPosition(win,620,420);
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
            if (options[0].highlightSprite(cursor->getSprite(),169,80) && active && /*mainWall*/) {
                //does nothing;
            } else if (options[1].highlightSprite(cursor->getSprite(),195,80) && active && /*mainWall*/) {
                // does nothing;
            } else if (options[2].highlightSprite(cursor->getSprite(),20,80) && active && /*mainWall*/) {
                // does nothing;
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