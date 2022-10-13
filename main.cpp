#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;


int lobby(){
    sf::RenderWindow window(sf::VideoMode(1000,600), "Hotel Lobby");
   //hotellobby
   sf::Texture pTexture;
   sf::Sprite playerImage;
   if(!pTexture.loadFromFile("lobby.png"))
      std::cout<<"Couldnt load image"<<std::endl;

   playerImage.setTexture(pTexture);

   int temp=0;
      while (window.isOpen()){
       sf::Event event;
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
       }
       window.clear();
       window.draw(playerImage);
       window.display();
      }
   return 0;
}
//generate window for the hotel room and display it
int room(){
   sf::RenderWindow window(sf::VideoMode(1000,600), "Hotel Room", sf::Style::Fullscreen);

   //hotelroom
   sf::Texture pTexture_one;
   sf::Sprite hotelRoom;
   if(!pTexture_one.loadFromFile("room.jpeg"))
      std::cout<<"Couldnt load image"<<std::endl;
   hotelRoom.setTexture(pTexture_one);
   //hotelRoom.setPosition(100,100);
   
   int temp=0;
      while (window.isOpen()){
       sf::Event event;
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
       }

      
       window.clear();
       window.draw(hotelRoom);
       window.display();
      
      }
   return 0;
}

int bar(){
   sf::RenderWindow window(sf::VideoMode(1000,600), "Bar");

   //hotelroom
   sf::Texture pTexture_one;
   sf::Sprite hotelBar;
   if(!pTexture_one.loadFromFile("hotelbar.jpg"))
      std::cout<<"Couldnt load image"<<std::endl;
   hotelBar.setTexture(pTexture_one);
   
      while (window.isOpen()){
       sf::Event event;
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
       }

      
       window.clear();
       window.draw(hotelBar);
       window.display();
      
      }
   return 0;
}

int toilets(){
   sf::RenderWindow window(sf::VideoMode(1000,600), "Hotel Bathrooms");

   //hotelroom
   sf::Texture pTexture_one;
   sf::Sprite hotelBathroom;
   if(!pTexture_one.loadFromFile("hotelbathroom.jpeg"))
      std::cout<<"Couldnt load image"<<std::endl;
   hotelBathroom.setTexture(pTexture_one);
   
      while (window.isOpen()){
       sf::Event event;
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
       }

      
       window.clear();
       window.draw(hotelBathroom);
       window.display();
      
      }
   return 0;
}


int gym(){
   sf::RenderWindow window(sf::VideoMode(1000,600), "Gym");

   //hotelroom
   sf::Texture pTexture_one;
   sf::Sprite hotelGym;
   if(!pTexture_one.loadFromFile("hotelgym.jpg"))
      std::cout<<"Couldnt load image"<<std::endl;
   hotelGym.setTexture(pTexture_one);
   
      while (window.isOpen()){
       sf::Event event;
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
       }

      
       window.clear();
       window.draw(hotelGym);
       window.display();
      
      }
   return 0;
}

int main(){
   int temp = 1;
   while (temp>0){
   cout << "Enter the number of the room you wish to go to: Lobby - 1,  Your Room - 2, Bar - 3, Bathroom - 4, Gym - 5,  0 to quit" << endl;
   cout << temp<< endl;
   cin >> temp;
   cout << temp <<endl;
   if (temp==1){
   lobby();
   } else if (temp==2){
      room();
   } else if (temp==3){
      bar();
   } else if (temp==4){
      toilets();
   }else if (temp==5){
      gym();
   }
   }
}