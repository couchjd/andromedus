#include "SpriteSheet.h"
#include "Util.h"

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

struct SpriteInfo
{
   std::string m_sheet_path;
   int m_x_res;
   int m_y_res;

   std::vector<std::vector<int>> m_sprite_coords;
};

void xmlTest(SpriteInfo& sprite_info);

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    
    std::string test_texture_path = SPRITES_FOLDER_PATH + "/chara2.png";

    sf::Texture test_texture;
    bool status = test_texture.loadFromFile(test_texture_path);

    SpriteSheet sprite_sheet(test_texture, 25, 36);

    SpriteInfo sprite_info;

    xmlTest(sprite_info);

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

void xmlTest(SpriteInfo& sprite_info)
{
   std::string path = RESOURCES_FOLDER_PATH + "/sprite_test.xml";
   
   rapidxml::file<> file(path.data());
   
   rapidxml::xml_document<> doc;

   doc.parse<0>(file.data());

   rapidxml::xml_node<>* first_node = doc.first_node();
   
   rapidxml::xml_attribute<>* attribute = first_node->first_attribute();
   sprite_info.m_sheet_path = attribute->value();

   attribute = attribute->next_attribute();
   sprite_info.m_x_res = std::atoi(attribute->value());

   attribute = attribute->next_attribute();
   sprite_info.m_y_res = std::atoi(attribute->value());

   int x_coord = 0;
   int y_coord = 0;

   for (const rapidxml::xml_node<>* node = first_node->first_node(); node; node = node->next_sibling())
   {
      rapidxml::xml_node<>* child_node = node->first_node();
      x_coord = std::atoi(child_node->value());
      y_coord = std::atoi(child_node->next_sibling()->value());

      sprite_info.m_sprite_coords.push_back({ x_coord, y_coord });
   }
}