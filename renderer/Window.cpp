#include "Window.h"

Window::Window() :
   m_gl_window(nullptr)
{
}

status_type Window::init(
	const int width,
	const int height,
	const char* title,
	const GLFWmonitor* monitor,
	const GLFWwindow* share)
{
	status_type status = SUCCESS;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_gl_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (m_gl_window == nullptr)
	{
		glfwTerminate();
		status = FAILURE;
	}
	GLenum err = 0;
	if (STATUS_IS_SUCCESS(status))
	{
		glfwMakeContextCurrent(m_gl_window);
		glfwSetFramebufferSizeCallback(m_gl_window, framebufferSizeCallback);
		glfwSetScrollCallback(m_gl_window, scrollCallback);

		err = glewInit();
		glewExperimental = true;
	}

   return status;
}

void Window::draw(Model& model, Shader& shader)
{
	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// don't forget to enable shader before setting uniforms
	shader.use();

	model.Draw(shader);
}

bool Window::shouldClose()
{
	bool should_close = true;

	if (m_gl_window)
	{
		should_close = glfwWindowShouldClose(m_gl_window);
	}

	return should_close;
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Window::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
}
