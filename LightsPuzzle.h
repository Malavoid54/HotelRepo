#ifndef LIGHTSPUZZLE_H
#define LIGHTSPUZZLE_H

#include "room.h"
#include "roomArrow.h"
#include "cursor.h"
#include "gameMenu.h"
#include "gameItem.h"

// first room puzzle
class LightsPuzzle: public Room {
    private:
        RenderWindow* store;
        RoomArrow* buttons;
        GameItem* options;
        bool mainWall;
        int nOptions;
    public:
        // constructor
        LightsPuzzle(RenderWindow* win) {
            // initialises room settings
            setRoom(320,0);
            active = false;
            mainWall = true;
            store = win;

            // defines the number of arrows and defines each one
            buttons = new RoomArrow[2];
            buttons[0].setPosition(win,1500,300);
            buttons[1].setPosition(win,100,(win->getSize().y)/2);
            buttons[1].flipButton();
        
            // creates the clickable buttons
            nOptions = 3;
            options = new GameItem[nOptions];
            for (int i = 0; i < nOptions; i++) {
                options[i].createSprite(12,21,6);
            }

            // positions the 3 options
            options[0].setPosition(win,555,305);
            options[1].setPosition(win,825,305);
            options[2].setPosition(win,1150,305);
        }

        // draws the room and items
        void draw(RenderWindow* win) {
            if (active) {
                // draws background
                win->draw(*background);

                // if the main wall, render the buttons
                if (mainWall) {
                    buttons[0].draw(win);
                // renders just the hint wall
                } else if (!mainWall) {
                    buttons[1].draw(win);
                    for (int i = 0; i < nOptions; i++) {
                        options[i].draw(win);
                    }
                }
            }
        }
        
        // handles button presses
        void buttonPress(Mouse_Cursor* cursor, Event e) {
            if (buttons[0].highlightSprite(cursor->getSprite(),211,0) && active && mainWall) {
                if (e.type == Event::MouseButtonPressed) {
                    // moves to new screen
                    if (e.mouseButton.button == Mouse::Left) {
                        setRoom(320,90);
                        mainWall = false;
                    }   
                }
            } else if (buttons[1].highlightSprite(cursor->getSprite(),211,0) && active && !mainWall) {
                if (e.type == Event::MouseButtonPressed) {
                    // moves back to original
                    if (e.mouseButton.button == Mouse::Left) {
                        setRoom(320,0);
                        mainWall = true;
                    }
                } 
            } else if (options[0].highlightSprite(cursor->getSprite(),0,73) && active && !mainWall) {
                if (e.type == Event::MouseButtonPressed) {
                    // close game if wrong
                    if (e.mouseButton.button == Mouse::Left) {
                        store->close();
                    }
                }
            } else if (options[1].highlightSprite(cursor->getSprite(),12,73) && active && !mainWall) {
                if (e.type == Event::MouseButtonPressed) {
                    // close game if wrong
                    if (e.mouseButton.button == Mouse::Left) {
                        store->close();
                    }
                }
            } else if (options[2].highlightSprite(cursor->getSprite(),24,73) && active && !mainWall) {
                // correct answer
                    if (e.mouseButton.button == Mouse::Left) {
                        active = false;
                    }
            }
        }
        
        // returns the state of the room
        bool getStatus() {
            return active;
        }

        ~LightsPuzzle() {
            delete [] buttons;
            delete [] options;
        }
};

#endif