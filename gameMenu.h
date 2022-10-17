#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>
#include <string>
#include "room.h"
#include "button.h"
#include "cursor.h"
#include "clickTest.h"

using namespace sf;

class GameMenu: public Room{
    private:
        Button* button;
        RenderWindow* store;
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
            win->draw(*background);
            for (int i = 0; i < 3; i++){
                button[i].draw(win);
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
                        //store->close();
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
