#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui/imgui.h"

#include <Window.h>

class Game
{
public:
   Game();
   void init();
   int run();
   void shutdown();

   void handleEvents();
   void update();
   void render();

private:
   Window* m_main_window;
   Camera* m_camera;
};