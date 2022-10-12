#pragma once

#include "framework.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class __declspec(dllexport) Renderer
{
public:
   Renderer();

   int init();

private:
   static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
   static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

   GLFWwindow* m_main_window;
   int m_window_width;
   int m_window_height;
};