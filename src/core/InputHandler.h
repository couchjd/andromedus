#pragma once

#include "ActorUpdateManager.h"
#include "EventHandler.h"
#include "WindowUpdateManager.h"

class InputHandler : public EventHandler
{
public:
	InputHandler();
	InputHandler(
		ActorUpdateManager* actor_update_manager,
		WindowUpdateManager* window_update_manager);

	void handleEvent(const sf::Event& event);

private:
	ActorUpdateManager* m_actor_update_manager;
	WindowUpdateManager* m_window_update_manager;
};