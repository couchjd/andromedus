//#pragma once
////#include "Camera.h"
//#include "Status.h"
//#include "Model.h"
//
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//class Window
//{
//public:
//   Window();
//
//   status_type init(
//      const int width,
//      const int height,
//      const char* title,
//      const GLFWmonitor* monitor = nullptr,
//      const GLFWwindow* share = nullptr);
//
//   void draw(Model& model, Shader& shader);
//
//   bool shouldClose();
//
//private:
//   static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
//   static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
//   
//   //Camera* m_camera;
//   GLFWwindow* m_gl_window;
//};