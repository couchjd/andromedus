#include "InputHandler.h"
#include "Game.h"
#include <iostream>

InputHandler::InputHandler(Game* game) :
   m_game(game)
{
}

void
InputHandler::handleEvent(sf::Event& event)
{
   if (event.type == sf::Event::Closed)
   {
      m_game->getWindowUpdateManager()->getMainWindow()->close();
   }

   if (event.type == sf::Event::KeyPressed ||
       event.type == sf::Event::KeyReleased ||
       event.type == sf::Event::MouseButtonPressed ||
       event.type == sf::Event::MouseButtonReleased)
   {
      m_game->enqueueEvent(event);
   }
}
