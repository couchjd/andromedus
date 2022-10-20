#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui/imgui.h"

#include "Window.h"

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

   Camera* getCamera();

   float lastX = SCR_WIDTH / 2.0f;
   float lastY = SCR_HEIGHT / 2.0f;
   bool firstMouse = true;

   // timing
   float deltaTime = 0.0f;
   float lastFrame = 0.0f;

private:
   // settings
   const unsigned int SCR_WIDTH = 1024;
   const unsigned int SCR_HEIGHT = 768;

   Window* m_main_window;
   Camera* m_camera;
};