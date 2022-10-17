#ifndef ROOM_H
#define ROOM_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace sf;
extern int ticker;

class Room{
    private:
        int size_w;
        int size_h;
    public:
        Room(int size_w,int size_h, std::string title, std::string filename) {
            RenderWindow window(VideoMode(size_w,size_h), title, Style::Close);
            Texture pTexture;
            Sprite playerImage;
            if(!pTexture.loadFromFile(filename))
                std::cout<<"Couldnt load image"<<std::endl;
            playerImage.setTexture(pTexture);
            window.setPosition(Vector2i(10, 50));
            while (window.isOpen()){
                Event event;
                while (window.pollEvent(event)){                
                    if (event.type == sf::Event::Closed){
                        window.close();
                    }
                    if (event.type == Event::KeyPressed) {
                        if (event.key.code == Keyboard::Escape) {
                            ticker++;
                            window.close();
                        }
                    }
                
                
                }
                
                window.clear();
                window.draw(playerImage);
                window.display();
        }
        }
        /*void displayroom(){
            while (window.isOpen()){
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(playerImage);
            window.display();
        }
        }*/

        ~Room(){}
};
#endif
