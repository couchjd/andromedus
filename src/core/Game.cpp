#include "Game.h"
#include "Util.h"

#include <Shader.h>

#include <iostream>

Game::Game() :
   m_test_window(nullptr)
{
}

void
Game::init()
{
   const char* method_name = "Game::Init()";

   DEBUG(method_name << " : Initializing subsystems.");

   m_test_window = new Window();
   m_test_window->init(800, 600, "TEST WINDOW");

   Shader shader((RESOURCES_FOLDER_PATH + "/vertex_shader.vs").c_str(), (RESOURCES_FOLDER_PATH + "/fragment_shader.fs").c_str());
   Model model(RESOURCES_FOLDER_PATH + "/objects/backpack.obj");

   m_test_window->draw(model, shader);
}

void
Game::run()
{
}

void 
Game::shutdown()
{
   delete m_test_window;
}

void Game::handleEvents()
{

}

void Game::update()
{

}

void Game::render()
{
   
}
