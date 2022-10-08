#pragma once

#include "EventHandler.h"

class ImGuiEventHandler : public EventHandler
{
	void handleEvent(sf::Event& event) override;
};