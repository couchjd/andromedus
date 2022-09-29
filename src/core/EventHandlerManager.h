#pragma once

#include "EventHandler.h"

#include <vector>

class EventHandlerManager
{
public:
	void addHandler(EventHandler* handler);
	void callHandlers(const sf::Event& event);

private:
	std::vector<EventHandler*> m_event_handlers;
};