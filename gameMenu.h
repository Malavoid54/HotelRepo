#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "room.h"
#include "button.h"
#include "cursor.h"

class GameMenu: public Room{
    private:
        Button* button;
        RenderWindow* store;
        Clock clock;
        Time time;
    public:
        GameMenu(RenderWindow* win) {
            button = new Button[3];
            for (int i = 0; i < 3; i++) {
                button[i].setPosition(win,(3-i));
            }
            button[2].setText("Start Game");
            button[1].setText("Load Game");
            button[0].setText("Quit Game");
            store = win;
            active = true;
        }
        void draw(RenderWindow* win) {
            if (active) {
                win->draw(*background);
                for (int i = 0; i < 3; i++){
                    button[i].draw(win);
                }
                time = clock.restart();
            } else if (!active) {
                time = clock.getElapsedTime();
                if (time.asSeconds() > 2 && time.asSeconds() < 5) {
                    setRoom(0,90);
                    win->draw(*background);
                } else if (time.asSeconds() > 2 && time.asSeconds() < 10) {
                    setRoom(0,180);
                    win->draw(*background);
                } else if (time.asSeconds() > 2 && time.asSeconds() < 15) {
                    setRoom(0,270);
                    win->draw(*background);
                }
            
            }
            
        }

        void buttonPress(Mouse_Cursor* cursor, Event e) {
            if (button[0].highlightSprite(cursor->getSprite()) && active) {
                if (e.type == Event::MouseButtonPressed) {
                    if (e.mouseButton.button == Mouse::Left) {
                        store->close();
                    }   
                }
            } else if (button[1].highlightSprite(cursor->getSprite()) && active) {
                if (e.type == Event::MouseButtonPressed) {
                    if (e.mouseButton.button == Mouse::Left) {
                        
                    }   
                }
            } else if (button[2].highlightSprite(cursor->getSprite()) && active) {
                if (e.type == Event::MouseButtonPressed) {
                    if (e.mouseButton.button == Mouse::Left) {
                        active = false;
                    }
                }
            }
        }

        ~GameMenu() {
            delete [] button;
            delete store;
        }
};

#endif
