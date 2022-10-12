#include "MouseHandler.h"

MouseHandler::MouseHandler() :
   m_selecting(false)
{
}

void MouseHandler::handleEvent(sf::Event& event)
{
   if (sf::Event::MouseButtonPressed == event.type)
   {
      if (sf::Mouse::Left == event.mouseButton.button && !m_selecting)
      {
         m_selection_start = sf::Mouse::getPosition();
         m_selecting = true;
      }
   }

   if (sf::Event::MouseButtonReleased == event.type)
   {
      if (sf::Mouse::Left == event.mouseButton.button && m_selecting)
      {
         m_selection_end = sf::Mouse::getPosition();
         m_selecting = false;
      }
   }
}

bool MouseHandler::isSelecting()
{
   return m_selecting;
}
