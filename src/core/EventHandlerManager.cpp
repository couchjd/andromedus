#include "EventHandlerManager.h"

void 
EventHandlerManager::addHandler(EventHandler* handler)
{
	m_event_handlers.push_back(handler);
}

void 
EventHandlerManager::callHandlers(const sf::Event& event)
{
	for (EventHandler* handler : m_event_handlers)
	{
		handler->handleEvent(event);
	}
}
