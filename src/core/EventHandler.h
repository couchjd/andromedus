#pragma once
#include <SFML/Window/Event.hpp>

class EventHandler
{
public:
	virtual void handleEvent(const sf::Event& event) = 0;
};