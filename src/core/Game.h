#pragma once

#include "ActorUpdateManager.h"
#include "EventHandlerManager.h"
#include "InputHandler.h"
#include "WindowUpdateManager.h"

#include "Character.h"
#include "Player.h"

#include <queue>

class Game
{
public:
   void init();
   void run();
   void shutdown();

   void handleEvents();
   void update();
   void render();

   Character* getMainCharacter();

   WindowUpdateManager* getWindowUpdateManager();

   ActorUpdateManager* getActorUpdateManager();

   void enqueueEvent(sf::Event event);

private:
   Player* m_main_character;
   sf::RenderWindow* m_main_window;
   ActorUpdateManager* m_actor_update_mgr;
   EventHandlerManager* m_event_handler_mgr;
   InputHandler* m_input_handler;
   WindowUpdateManager* m_window_update_mgr;

   std::queue<sf::Event> m_update_queue;
};