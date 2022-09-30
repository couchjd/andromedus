#pragma once

#include "ActorUpdateManager.h"
#include "EventHandlerManager.h"
#include "InputHandler.h"

#include "Character.h"

class Game
{
public:
   void init();
   void run();
   void shutdown();

   void handleEvents();
   void update();
   void render();

private:
   Character* m_main_character;
   sf::RenderWindow* m_main_window;
   ActorUpdateManager* m_actor_update_mgr;
   EventHandlerManager* m_event_handler_mgr;
   InputHandler* m_input_handler;
};