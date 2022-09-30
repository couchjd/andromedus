#include "EventHandlerManager.h"

void 
EventHandlerManager::addHandler(EventHandler* handler)
{
	m_event_handlers.push_back(handler);
}

void 
EventHandlerManager::handleEvent(const sf::Event& event)
{
	callHandlers(event);
}

void 
EventHandlerManager::callHandlers(const sf::Event& event)
{
	for (EventHandler* handler : m_event_handlers)
	{
		handler->handleEvent(event);
	}
}
