#include "Game.h"

#define MS_PER_UPDATE 30

void 
Game::init()
{
   m_main_character = new Character();
   m_main_character->init();

   m_actor_update_mgr = new ActorUpdateManager();
   m_actor_update_mgr->addActor(m_main_character);
   
   m_input_handler = new InputHandler();
   m_event_handler_mgr = new EventHandlerManager();
   m_event_handler_mgr->addHandler(m_input_handler);

   m_main_window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML works!");
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
}

void 
Game::shutdown()
{
   delete m_main_window;
   delete m_event_handler_mgr;
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

}

void Game::render()
{
   m_main_window->clear();
   m_main_window->draw(*m_main_character);
   m_main_window->display();
}
