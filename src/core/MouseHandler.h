#pragma once

#include "EventHandler.h"

#include <SFML/Graphics.hpp>

class MouseHandler : public EventHandler
{
public:
   MouseHandler();

   void handleEvent(sf::Event& event) override;

   bool isSelecting();
private:
   bool m_selecting;
   sf::Vector2i m_selection_start;
   sf::Vector2i m_selection_end;
};
