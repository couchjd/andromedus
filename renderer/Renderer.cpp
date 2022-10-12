// renderer.cpp : Defines the functions for the static library.
//

#include "Renderer.h"

Renderer::Renderer() :
	m_main_window(nullptr),
	m_window_width(800),
	m_window_height(600)
{
}

int Renderer::init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_main_window = glfwCreateWindow(m_window_width, m_window_height, "Andromedus", nullptr, nullptr);
	if (m_main_window == nullptr)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(m_main_window);
	glfwSetFramebufferSizeCallback(m_main_window, framebufferSizeCallback);
	glfwSetScrollCallback(m_main_window, scrollCallback);

	glewInit();
	glewExperimental = true;

	const char* glsl_version = "#version 330";
}

void Renderer::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Renderer::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
}
