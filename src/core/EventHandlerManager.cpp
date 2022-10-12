#include "EventHandlerManager.h"

EventHandlerManager::~EventHandlerManager()
{
	deleteAllHandlers();
}

void
EventHandlerManager::addHandler(EventHandler* handler)
{
	m_event_handlers.push_back(handler);
}

void 
EventHandlerManager::handleEvent(sf::Event& event)
{
	callHandlers(event);
}

void 
EventHandlerManager::callHandlers(sf::Event& event)
{
	for (EventHandler* handler : m_event_handlers)
	{
		handler->handleEvent(event);
	}
}

void EventHandlerManager::deleteAllHandlers()
{
	for (EventHandler* handler : m_event_handlers)
	{
		delete(handler);
	}

	m_event_handlers.clear();
}
