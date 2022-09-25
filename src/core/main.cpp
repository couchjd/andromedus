#include "Animation.h"
#include "Character.h"
#include "SpriteSheet.h"
#include "Util.h"

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

void xmlTest(SpriteSheet& sprite_sheet);

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    
    SpriteSheet sprite_sheet;
    xmlTest(sprite_sheet);

    Animation test_animation;

    test_animation.insertAnimationFrame(0, sprite_sheet[0]);
    //test_animation.insertAnimationFrame(1, sprite_sheet[1]);
    test_animation.insertAnimationFrame(1, sprite_sheet[2]);
    //test_animation.insertAnimationFrame(3, sprite_sheet[3]);
    //test_animation.insertAnimationFrame(4, sprite_sheet[4]);
    //test_animation.insertAnimationFrame(5, sprite_sheet[5]);

    Character test_character;

    test_character.addMovementAnimation(FORWARD, &test_animation);

    sf::Clock clock;
    clock.restart();

    sf::Sprite* anim_sprite = test_animation.getNextFrame();
    
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
           anim_sprite = test_animation.getNextFrame();
           clock.restart();
        }

        window.clear();
        window.draw(test_character);
        window.display();
    }

    return 0;
}

void xmlTest(SpriteSheet& sprite_sheet)
{
   std::string path = RESOURCES_FOLDER_PATH + "/sprite_test.xml";
   
   rapidxml::file<> file(path.data());
   rapidxml::xml_document<> doc;
   doc.parse<0>(file.data());

   sprite_sheet.init(doc);
}