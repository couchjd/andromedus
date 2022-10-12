#include "Game.h"

#include "FileOpenWindow.h"
#include "MouseHandler.h"

#include <iostream>

Game::Game() :
   m_main_character(nullptr)
{
}

void
Game::init()
{
   const char* method_name = "Game::Init()";

   DEBUG(method_name << " : Initializing subsystems.");

   m_main_window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML works!");
   
   initializeManagers();

   m_main_character = new Player();
   m_main_character->init();
   m_actor_update_mgr->addActor(m_main_character);

   FileOpenWindow* file_open_window = new FileOpenWindow();
   m_imgui_manager->addWindow(file_open_window);

   initializeHandlers();
}

void
Game::run()
{
   sf::Clock clock;
   double previous = clock.restart().asMilliseconds();

   m_main_window->resetGLStates();

   while (m_main_window->isOpen())
   {
      handleEvents();

      update(clock.restart());

      render();
   }

   shutdown();
}

void 
Game::shutdown()
{
   delete m_imgui_manager;
   
   delete m_window_update_mgr;
   
   delete m_event_handler_mgr;
   
   delete m_main_character;
   
   delete m_actor_update_mgr;

   delete m_main_window;
}

void Game::handleEvents()
{
   sf::Event event;
   while (m_main_window->pollEvent(event))
   {
      m_event_handler_mgr->handleEvent(event);
   }
}

void Game::update(sf::Time time)
{
   if(m_imgui_manager)
   {
      m_imgui_manager->update(time);
   }

   while (!m_update_queue.empty())
   {
      sf::Event event = m_update_queue.front();
      
      DEBUG("Handling event type: " << sf_event_types[event.type] << "\n\tKey/Button Code : " << event.key.code)
      m_actor_update_mgr->update(event);
      m_update_queue.pop();
   }
}

void Game::render()
{
   m_main_window->clear();

   m_main_window->draw(*m_main_character);
   m_imgui_manager->render();
   m_main_window->display();
   
}

Character* Game::getMainCharacter()
{
    return m_main_character;
}

WindowUpdateManager* Game::getWindowUpdateManager()
{
   return m_window_update_mgr;
}

ActorUpdateManager* Game::getActorUpdateManager()
{
   return m_actor_update_mgr;
}

void Game::enqueueEvent(sf::Event event)
{
   m_update_queue.push(event);
}

void Game::initializeManagers()
{
   m_actor_update_mgr = new ActorUpdateManager();

   m_event_handler_mgr = new EventHandlerManager();

   m_window_update_mgr = new WindowUpdateManager(m_main_window);

   m_imgui_manager = new ImGuiUIManager(m_main_window);
}

void Game::initializeHandlers()
{
   m_event_handler_mgr->addHandler(new InputHandler(this));
   m_event_handler_mgr->addHandler(new ImGuiEventHandler());
   m_event_handler_mgr->addHandler(new MouseHandler());
}

