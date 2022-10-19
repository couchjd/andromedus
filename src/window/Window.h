#pragma once

#include <Camera.h>
#include <Model.h>
#include <Shader.h>
#include <Status.h>

#include <Util.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void processInput(GLFWwindow* window);
void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void mouseCallback(GLFWwindow* window, double xposIn, double yposIn);
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

class Window
{
public:
   Window();

   status_type init(
      const int width,
      const int height,
      const char* title,
      const GLFWmonitor* monitor = nullptr,
      const GLFWwindow* share = nullptr);

   void draw(Model& model, Shader& shader);

   bool shouldClose();

   GLFWwindow* getGLWindow();

private:

   
   GLFWwindow* m_gl_window;
   Camera* m_camera;
};

