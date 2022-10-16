#ifndef ROOM_H
#define ROOM_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace sf;

class Room{
    private:
        int size_w;
        int size_h;
    public:
        Room(int size_w,int size_h, std::string title, std::string filename) {
            RenderWindow window(VideoMode(size_w,size_h), title);
            Texture pTexture;
            Sprite playerImage;
            if(!pTexture.loadFromFile(filename))
                std::cout<<"Couldnt load image"<<std::endl;
            playerImage.setTexture(pTexture);
        }
        void displayroom(){

            
        }



};
#endif
