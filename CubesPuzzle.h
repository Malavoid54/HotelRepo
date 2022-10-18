#ifndef CUBESPUZZLE_H
#define CUBESPUZZLE_H

#include "room.h"
#include "roomArrow.h"
#include "cursor.h"
#include "gameMenu.h"
#include "gameItem.h"

// Cubes puzzle
class CubesPuzzle: public Room {
    private:
        RoomArrow* buttons;
        GameItem* options;
        bool mainWall;
        int nOptions;
        bool answerOne;
        bool answerTwo;
    public:
        // constructor
        CubesPuzzle(RenderWindow* win) {
            // initialises room settings
            setRoom(160,180);
            active = false;
            mainWall = true;
            answerOne = false;
            answerTwo = false;

            // defines the number of arrows and defines each one
            buttons = new RoomArrow[2];
            buttons[0].setPosition(win,1500,0);
            buttons[1].setPosition(win,100,0);
            buttons[1].flipButton();
        
            // creates the clickable buttons
            nOptions = 6;
            options = new GameItem[nOptions];
            for (int i = 0; i < nOptions; i++) {
                options[i].createSprite(13,11,6);
            }

            // positions the 3 options
            options[0].setPosition(win,200,280);
            options[1].setPosition(win,200,310);
            options[2].setPosition(win,200,340);
            options[3].setPosition(win,260,280);
            options[4].setPosition(win,260,310);
            options[5].setPosition(win,260,340);
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
            if (buttons[0].highlightSprite(cursor->getSprite(),200,0) && active && mainWall) {
                if (e.type == Event::MouseButtonPressed) {
                    // moves to new screen
                    if (e.mouseButton.button == Mouse::Left) {
                        setRoom(160,270);
                        mainWall = false;
                    }   
                }
            } else if (buttons[1].highlightSprite(cursor->getSprite(),200,0) && active && !mainWall) {
                if (e.type == Event::MouseButtonPressed) {
                    // moves back to original
                    if (e.mouseButton.button == Mouse::Left) {
                        setRoom(160,180);
                        mainWall = true;
                    }
                } 
            } else if (options[0].highlightSprite(cursor->getSprite(),39,40) && active && !mainWall) {
                // does nothing;
            } else if (options[1].highlightSprite(cursor->getSprite(),39,51) && active && !mainWall) {
                if (e.type == Event::MouseButtonPressed) {
                    // correct answer
                    if (e.mouseButton.button == Mouse::Left) {
                        answerOne = true;
                    }
                }
            } else if (options[2].highlightSprite(cursor->getSprite(),39,62) && active && !mainWall) {
                // does nothing;
            } else if (options[3].highlightSprite(cursor->getSprite(),65,40) && active && !mainWall) {
                // does nothing;
            } else if (options[4].highlightSprite(cursor->getSprite(),65,51) && active && !mainWall) {
                // does nothing;
            } else if (options[5].highlightSprite(cursor->getSprite(),65,62) && active && !mainWall) {
                if (e.type == Event::MouseButtonPressed) {
                    // correct answer
                    /*if (e.mouseButton.button == Mouse::Left) {
                        answerTwo = true;
                        if (answerOne && answerTwo){
                            active = false;
                        }
                    }*/
                }
            }
        }
        
        // returns the state of the room
        bool getStatus() {
            return active;
        }

        ~CubesPuzzle() {
            delete [] buttons;
            delete [] options;
        }
};

#endif