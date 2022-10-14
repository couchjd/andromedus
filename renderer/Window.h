#pragma once
#include "Status.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class __declspec(dllexport) Window
{
public:
   Window();

   status_type init(
      const int width,
      const int height,
      const char* title,
      const GLFWmonitor* monitor = nullptr,
      const GLFWwindow* share = nullptr);

private:
   static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
   static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
   
   GLFWwindow* m_gl_window;
};