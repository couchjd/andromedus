#pragma once

#include "framework.h"

#include "Window.h"

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
};