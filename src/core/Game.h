#pragma once

#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include "ActorUpdateManager.h"
#include "EventHandlerManager.h"
#include "ImGuiUiManager.h"
#include "InputHandler.h"
#include "WindowUpdateManager.h"

#include "Character.h"
#include "Player.h"

#include <queue>

class Game
{
public:
   Game();
   void init();
   void run();
   void shutdown();

   void handleEvents();
   void update(sf::Time time);
   void render();

   Character* getMainCharacter();

   WindowUpdateManager* getWindowUpdateManager();

   ActorUpdateManager* getActorUpdateManager();

   void enqueueEvent(sf::Event event);

private:
   void initializeManagers();
   void initializeHandlers();

   Player* m_main_character;
   sf::RenderWindow* m_main_window;
   ActorUpdateManager* m_actor_update_mgr;
   EventHandlerManager* m_event_handler_mgr;
   WindowUpdateManager* m_window_update_mgr;
   ImGuiUIManager* m_imgui_manager;

   std::queue<sf::Event> m_update_queue;
};