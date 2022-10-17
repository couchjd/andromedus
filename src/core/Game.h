#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui/imgui.h"

//#include <Window.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);

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
   //Window* m_test_window;
};