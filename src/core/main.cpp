#include "ActorUpdateManager.h"
#include "Animation.h"
#include "Character.h"
#include "EventHandlerManager.h"
#include "InputHandler.h"
#include "SpriteSheet.h"
#include "Util.h"
#include "WindowUpdateManager.h"s

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

void xmlTest(SpriteSheet& sprite_sheet);

int main()
{
   EventHandlerManager event_handler_manager;
   
   sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
   WindowUpdateManager window_update_manager(&window);

   ActorUpdateManager actor_update_manager;

   InputHandler input_handler(&actor_update_manager, &window_update_manager);
   event_handler_manager.addHandler(&input_handler);



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

   sf::Clock clock;
   clock.restart();

   while (window.isOpen())
   {
      sf::Event event;
      while (window.pollEvent(event))
      {
         event_handler_manager.callHandlers(event);
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