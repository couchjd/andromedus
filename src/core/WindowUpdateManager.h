#pragma once

#include <SFML/Graphics.hpp>

class WindowUpdateManager
{
public:
   WindowUpdateManager();

   WindowUpdateManager(sf::RenderWindow* main_window);

   sf::RenderWindow*
   getMainWindow();

private:
   sf::RenderWindow* m_main_window;
};