#include "InputHandler.h"
#include <iostream>

InputHandler::InputHandler() :
   m_actor_update_manager(nullptr),
   m_window_update_manager(nullptr)
{
}

InputHandler::InputHandler(
   ActorUpdateManager* actor_update_manager, 
   WindowUpdateManager* window_update_manager) :
   m_actor_update_manager(actor_update_manager),
   m_window_update_manager(window_update_manager)
{
}

void
InputHandler::handleEvent(const sf::Event& event)
{
   if (event.type == sf::Event::Closed)
   {
      m_window_update_manager->getMainWindow()->close();
   }

   if (event.type == sf::Event::KeyPressed)
   {
      switch (event.key.code)
      {
         case sf::Keyboard::W:
         case sf::Keyboard::A:
         case sf::Keyboard::S:
         case sf::Keyboard::D:
         {
            m_actor_update_manager->update(event);
            break;
         }
         default:
         {
            break;
         }
      }
   }

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::D))
   {
      //test_character.setIsMoving(true);
   }
   else
   {
      if (true/*test_character.getIsMoving()*/)
      {
         //test_character.setIsMoving(false);
      }
   }
}
