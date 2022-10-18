#ifndef CHESSPUZZLE_H
#define CHESSPUZZLE_H

#include "room.h"
#include "roomArrow.h"
#include "cursor.h"
#include "gameMenu.h"

// first room puzzle
class ChessPuzzle: public Room {
    private:
        RenderWindow* store;
        RoomArrow* buttons;
        bool mainWall;
    public:
        // constructor
        ChessPuzzle(RenderWindow* win) {
            buttons = new RoomArrow[2];
            buttons[0].setPosition(win,1500,0);
            buttons[1].setPosition(win,100,0);
            buttons[1].flipButton();
            setRoom(160,0);
            active = false;
            store = win;
            bool mainWall = true;
        }
        // draws the room and items
        void draw(RenderWindow* win) {
            if (active) {
                win->draw(*background);
                if (mainWall) {
                    buttons[0].draw(win);
                } else if (!mainWall) {
                    buttons[1].draw(win);
                }
            }
        }
        
        // handles button presses
        void buttonPress(Mouse_Cursor* cursor, Event e) {
            if (buttons[0].highlightSprite(cursor->getSprite()) && active && mainWall) {
                if (e.type == Event::MouseButtonPressed) {
                    // moves to new screen
                    if (e.mouseButton.button == Mouse::Left) {
                        setRoom(160,90);
                        mainWall = false;
                    }   
                }
            } else if (buttons[1].highlightSprite(cursor->getSprite()) && active && !mainWall) {
                if (e.type == Event::MouseButtonPressed) {
                    // moves back to original
                    if (e.mouseButton.button == Mouse::Left) {
                        setRoom(160,0);
                        mainWall = true;
                    }
                }
            } 
        }
        
        // returns the state of the room
        bool getStatus() {
            return active;
        }

        ~ChessPuzzle() {}
};

#endif