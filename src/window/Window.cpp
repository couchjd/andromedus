#include "Window.h"

#include <Game.h>

Window::Window() :
	m_gl_window(nullptr),
	m_camera(nullptr)
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
		glfwSetCursorPosCallback(m_gl_window, mouseCallback);
		glfwSetScrollCallback(m_gl_window, scrollCallback);

		glfwSetInputMode(m_gl_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

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

GLFWwindow* Window::getGLWindow()
{

}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
	Game* game = reinterpret_cast<Game*>(glfwGetWindowUserPointer(window));
	
	Camera* camera = game->getCamera();

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera->ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera->ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera->ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera->ProcessKeyboard(RIGHT, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouseCallback(GLFWwindow* window, double xposIn, double yposIn)
{
	Game* game = reinterpret_cast<Game*>(glfwGetWindowUserPointer(window));

	Camera* camera = game->getCamera();

	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	camera->ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	Game* game = reinterpret_cast<Game*>(glfwGetWindowUserPointer(window));

	Camera* camera = game->getCamera();

	camera->ProcessMouseScroll(static_cast<float>(yoffset));
}
