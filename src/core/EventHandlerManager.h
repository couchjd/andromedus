#pragma once

#include "EventHandler.h"

#include <vector>

class EventHandlerManager
{
public:
	~EventHandlerManager();
	void addHandler(EventHandler* handler);
	void handleEvent(sf::Event& event);

private:
	std::vector<EventHandler*> m_event_handlers;
	void callHandlers(sf::Event& event);
	void deleteAllHandlers();
};