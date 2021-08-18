#include <SFML/Graphics.hpp>
#include <iostream>
#include <render.hpp>

int main()
{
    //native NES screen 256:240, 16:15 ratio
    const float initPixScale = 2;
    sf::RenderWindow window(sf::VideoMode(256*initPixScale, 240*initPixScale), "SFML Tests");
    sf::RectangleShape pixel(sf::Vector2f(initPixScale, initPixScale));

    

    while (window.isOpen())
    {
        //Event polling
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::Resized:
                    window.setSize(sf::Vector2u(window.getSize().x, window.getSize().x*15/16));
                    break;

                default:
                    break;
            }
        }

        //render pixels
        window.clear();

        for (int i = 0; i < 240; i++) {
            for (int j = 0; j < 256; j++) {
                pixel.setFillColor(sf::Color(i, j, 0));
                pixel.setPosition(sf::Vector2f(initPixScale*j, initPixScale*i));
                window.draw(pixel);
            }
        }

        window.display();
    }

    return 0;
}

