#include "WindowUpdateManager.h"

WindowUpdateManager::WindowUpdateManager() :
   m_main_window(nullptr)
{
}

WindowUpdateManager::WindowUpdateManager(sf::RenderWindow* main_window) :
   m_main_window(main_window)
{
}

sf::RenderWindow* 
WindowUpdateManager::getMainWindow()
{
   return m_main_window;
}
