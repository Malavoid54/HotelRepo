#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


int main(){
   sf::RenderWindow window(sf::VideoMode(1000,1000), "SFML works!");
   //sf::CircleShape shape(100.f);
   //shape.setFillColor(sf::Color::Green);
   sf::Texture pTexture;
   sf::Sprite playerImage;
   if(!pTexture.loadFromFile("lobby.png"))
      std::cout<<"Couldnt load image"<<std::endl;

   playerImage.setTexture(pTexture);
    int temp = 0;
     if (temp = 0){    
    while (window.isOpen())
    {
       sf::Event event;
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
       }

       window.clear();
       //window.draw(shape);
       window.draw(playerImage);
       window.display();
    }
    }
 
   
   return 0;
}