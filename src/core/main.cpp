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

   forward.insertAnimationFrame(0, sprite_sheet[0]);
   forward.insertAnimationFrame(1, sprite_sheet[1]);
   forward.insertAnimationFrame(2, sprite_sheet[2]);
   left.insertAnimationFrame(3, sprite_sheet[3]);
   left.insertAnimationFrame(4, sprite_sheet[4]);
   left.insertAnimationFrame(5, sprite_sheet[5]);
   back.insertAnimationFrame(6, sprite_sheet[6]);
   back.insertAnimationFrame(7, sprite_sheet[7]);
   back.insertAnimationFrame(8, sprite_sheet[8]);
   right.insertAnimationFrame(9, sprite_sheet[9]);
   right.insertAnimationFrame(10, sprite_sheet[10]);
   right.insertAnimationFrame(11, sprite_sheet[11]);

   Character test_character;

   test_character.addMovementAnimation(FORWARD, &forward);
   test_character.addMovementAnimation(LEFT, &left);
   test_character.addMovementAnimation(BACKWARD, &back);
   test_character.addMovementAnimation(RIGHT, &right);

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
         test_character.update(event);
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