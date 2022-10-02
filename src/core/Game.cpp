#include "Game.h"
#include <iostream>

#define MS_PER_UPDATE 30

void 
Game::init()
{
   const char* method_name = "Game::Init()";

   DEBUG(method_name << " : Initializing subsystems.")

   m_main_character = new Player();
   m_main_character->init();
   DEBUG("Player character initialized. Actor ID: " << m_main_character->getActorId())

   m_actor_update_mgr = new ActorUpdateManager();
   m_actor_update_mgr->addActor(m_main_character);
   
   m_input_handler = new InputHandler(this);
   m_event_handler_mgr = new EventHandlerManager();
   m_event_handler_mgr->addHandler(m_input_handler);

   DEBUG("Creating main window.")
   m_main_window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML works!");
   m_window_update_mgr = new WindowUpdateManager(m_main_window);
}

void
Game::run()
{
   sf::Clock clock;
   double previous = clock.restart().asMilliseconds();
   double lag = 0.0;

   while (m_main_window->isOpen())
   {
      double current = clock.getElapsedTime().asMilliseconds();
      double elapsed = current - previous;
      previous = current;
      lag += elapsed;

      handleEvents();

      while (lag >= MS_PER_UPDATE)
      {
         update();
         lag -= MS_PER_UPDATE;
      }

      render();
   }

   shutdown();
}

void 
Game::shutdown()
{
   delete m_main_window;
   delete m_event_handler_mgr;
   delete m_input_handler;
   delete m_actor_update_mgr;
   delete m_main_character;
}

void Game::handleEvents()
{
   sf::Event event;
   while (m_main_window->pollEvent(event))
   {
      m_event_handler_mgr->handleEvent(event);
   }
}

void Game::update()
{
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
