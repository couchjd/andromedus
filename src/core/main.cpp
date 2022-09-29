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

   Animation forward;
   Animation left;
   Animation back;
   Animation right;

   forward.setIdleSprite(sprite_sheet[1]);
   forward.insertAnimationFrame(0, sprite_sheet[0]);
   forward.insertAnimationFrame(1, sprite_sheet[2]);
   left.setIdleSprite(sprite_sheet[4]);
   left.insertAnimationFrame(0, sprite_sheet[3]);
   left.insertAnimationFrame(1, sprite_sheet[5]);
   back.setIdleSprite(sprite_sheet[10]);
   back.insertAnimationFrame(0, sprite_sheet[9]);
   back.insertAnimationFrame(1, sprite_sheet[11]);
   right.setIdleSprite(sprite_sheet[7]);
   right.insertAnimationFrame(0, sprite_sheet[6]);
   right.insertAnimationFrame(1, sprite_sheet[8]);

   Character test_character;

   test_character.addMovementAnimation(FORWARD, &forward);
   test_character.addMovementAnimation(LEFT, &left);
   test_character.addMovementAnimation(BACKWARD, &back);
   test_character.addMovementAnimation(RIGHT, &right);

   sf::Shader shader;
   std::string v_shader_path = RESOURCES_FOLDER_PATH + "/bloom.vs";
   std::string f_shader_path = RESOURCES_FOLDER_PATH + "/bloom.fs";

   if (!shader.loadFromFile(v_shader_path, f_shader_path))
   {
      std::cout << "FAILED TO LOAD SHADER!\n";
   }

   sf::Clock clock;
   clock.restart();

   while (window.isOpen())
   {
      sf::Event event;
      while (window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
            window.close();
         if (event.type == sf::Event::KeyPressed)
         {
            switch (event.key.code)
            {
               case sf::Keyboard::W:
               {
                  test_character.setFacing(BACKWARD);
                  break;
               }
               case sf::Keyboard::A:
               {
                  test_character.setFacing(LEFT);
                  break;
               }
               case sf::Keyboard::S:
               {
                  test_character.setFacing(FORWARD);
                  break;
               }
               case sf::Keyboard::D:
               {
                  test_character.setFacing(RIGHT);
                  break;
               }
            }
         }

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::D))
         {
            test_character.setIsMoving(true);
         }
         else
         {
            if (test_character.getIsMoving())
            {
               test_character.setIsMoving(false);
            }
         }
      }

      float elapsed = clock.getElapsedTime().asSeconds();


      if (elapsed >= 0.25f)
      {
         test_character.update(event);
         clock.restart();
      }

      window.clear();
      window.draw(test_character, &shader);
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