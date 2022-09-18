#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::R)
                {
                    shape.setFillColor(sf::Color::Red);
                }
                if (event.key.code == sf::Keyboard::B)
                {
                    shape.setFillColor(sf::Color::Blue);
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}