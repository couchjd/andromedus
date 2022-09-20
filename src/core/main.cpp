#include "SpriteSheet.h"
#include "Util.h"

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    
    std::string test_texture_path = SPRITES_FOLDER_PATH + "/chara2.png";

    sf::Texture test_texture;
    bool status = test_texture.loadFromFile(test_texture_path);

    SpriteSheet sprite_sheet(test_texture, 25, 36);
        
    sf::Clock clock;
    clock.restart();

    int anim_sprite = 0;

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
                    
                }
                if (event.key.code == sf::Keyboard::B)
                {
                    
                }
            }
        }

        float elapsed = clock.getElapsedTime().asSeconds();
        if (elapsed >= 0.25f)
        {
           anim_sprite = (anim_sprite == 0) ? 2 : 0;
           clock.restart();
        }

        window.clear();
        window.draw(*sprite_sheet[anim_sprite]);
        window.display();
    }

    return 0;
}