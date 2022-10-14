// renderer.cpp : Defines the functions for the static library.
//

#include "Renderer.h"

Renderer::Renderer()
{
}

int Renderer::init()
{
	glewInit();
	glewExperimental = true;

	const char* glsl_version = "#version 330";

	return 0;
}

void Renderer::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Renderer::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
}
