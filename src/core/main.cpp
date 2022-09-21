#include "SpriteSheet.h"
#include "Util.h"

#include <rapidxml/rapidxml.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

void xmlTest();

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    
    std::string test_texture_path = SPRITES_FOLDER_PATH + "/chara2.png";

    sf::Texture test_texture;
    bool status = test_texture.loadFromFile(test_texture_path);

    SpriteSheet sprite_sheet(test_texture, 25, 36);

    xmlTest();

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

void xmlTest()
{
   std::string test_xml_path = RESOURCES_FOLDER_PATH + "/test.xml";

   struct stat sb {};
   std::string res;

#pragma warning(suppress : 4996)
   FILE* input_file = fopen(test_xml_path.c_str(), "r");

   stat(test_xml_path.c_str(), &sb);
   res.resize(sb.st_size);
   fread(const_cast<char*>(res.data()), sb.st_size, 1, input_file);
   fclose(input_file);

   rapidxml::xml_document<> doc;
   doc.parse<0>(const_cast<char*>(res.data()));

   std::cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
}