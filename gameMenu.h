#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "room.h"
#include "button.h"
#include "cursor.h"

// class for the game's menu and initial sequence
class GameMenu: public Room{
    private:
        // button array
        Button* button;
        RenderWindow* store;

        // variables used for delaying commands
        Clock clock;
        Time time;
        bool loop;
    public:
        // constructor for the menu
        GameMenu(RenderWindow* win) {
            // creates three buttons at a fixed position and name
            button = new Button[3];
            for (int i = 0; i < 3; i++) {
                button[i].setPosition(win,0,(3-i));
            }
            button[2].setText("Start Game");
            button[1].setText("Load Game");
            button[0].setText("Quit Game");
            store = win; // stores a local copy of the window pointer
            active = true; // sets the room to be true
            loop = true;
        }

        // draws the background and the buttons
        void draw(RenderWindow* win) {
            if (loop) {
                if (active) {
                    // draws buttons and menu background
                    win->draw(*background);
                    for (int i = 0; i < 3; i++){
                        button[i].draw(win);
                    }
                    time = clock.restart(); // keeps the clock at 0
                } else if (!active) {
                    time = clock.getElapsedTime(); // grabs the time elapsed since starting
                    // switches between the three intro sequence, 5 seconds for each image
                    if (time.asSeconds() > 2 && time.asSeconds() < 7) {
                        setRoom(0,90);
                        win->draw(*background);
                    } else if (time.asSeconds() > 2 && time.asSeconds() < 12) {
                        setRoom(0,180);
                        win->draw(*background);
                    } else if (time.asSeconds() > 2 && time.asSeconds() < 17) {
                        setRoom(0,270);
                        win->draw(*background);
                    } else if (time.asSeconds() >= 17) {
                        loop = false;
                    }
                }
            }
            
        }

        // function that determines what each of the three buttons does
        void buttonPress(Mouse_Cursor* cursor, Event e) {
            if (button[0].highlightSprite(cursor->getSprite()) && active) {
                if (e.type == Event::MouseButtonPressed) {
                    // quits the game
                    if (e.mouseButton.button == Mouse::Left) {
                        store->close();
                    }   
                }
            } else if (button[1].highlightSprite(cursor->getSprite()) && active) {
                if (e.type == Event::MouseButtonPressed) {
                    // loads a save
                    if (e.mouseButton.button == Mouse::Left) {
                        
                    }   
                }
            } else if (button[2].highlightSprite(cursor->getSprite()) && active) {
                if (e.type == Event::MouseButtonPressed) {
                    // sets the menu to be inactive and plays title sequence
                    if (e.mouseButton.button == Mouse::Left) {
                        active = false;
                    }
                }
            }
        }

        bool getStatus () {
            return loop;
        }

        ~GameMenu() {
            delete [] button;
            delete store;
        }
};

#endif
