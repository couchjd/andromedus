#pragma once

#include "ActorUpdateManager.h"
#include "EventHandler.h"
#include "WindowUpdateManager.h"

class Game;

class InputHandler : public EventHandler
{
public:
	InputHandler(Game* game);

	void handleEvent(sf::Event& event) override;

private:
	Game* m_game;
};