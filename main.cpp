#include <SFML/Graphics.hpp>
#include <iostream>
#include <render.hpp>

int main()
{
    //native NES screen 256:240, 16:15 ratio
    sf::RenderWindow window(sf::VideoMode(522, 490), "SFML Tests");
    sf::RectangleShape rectangle(sf::Vector2f(512.f, 480.f));
    rectangle.setPosition(5.f, 5.f);
    rectangle.setFillColor(sf::Color::Green);
    

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

        //render sizing logic

        // if (window.getSize().x >= window.getSize().y) {
        //     layout_margin = window.getSize().x * 0.05;
        //     layout_width = window.getSize().x * 0.9;
        //     layout_height = layout_width * 15/16;
        //     rectangle.setPosition(layout_margin, layout_margin);
        //     rectangle.setSize(sf::Vector2f(layout_width, layout_height));
        // }

        // std::cout << "window:" << std::endl;
        // std::cout << window.getSize().x << std::endl;
        // std::cout << "position:" << std::endl;
        // std::cout << layout_pos_x << std::endl;
        // std::cout << "Size:" << std::endl;
        // std::cout << layout_size_x << std::endl;

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}

