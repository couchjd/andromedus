#include "Game.h"
#include "Util.h"

#include <Camera.h>
#include <Shader.h>
#include <Model.h>
#include <stb_image.h>

#include <iostream>

// settings
const unsigned int SCR_WIDTH = 1024;
const unsigned int SCR_HEIGHT = 768;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 9.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

Game::Game() //:
   //m_test_window(nullptr)
{
}

void
Game::init()
{
   const char* method_name = "Game::Init()";

   DEBUG(method_name << " : Initializing subsystems.");

   //m_test_window = new Window();
   //m_test_window->init(800, 600, "TEST WINDOW");

   //Shader shader((RESOURCES_FOLDER_PATH + "/vertex_shader.vs").c_str(), (RESOURCES_FOLDER_PATH + "/fragment_shader.fs").c_str());
   //Model model(RESOURCES_FOLDER_PATH + "/objects/backpack.obj");

   //m_test_window->draw(model, shader);
}

int
Game::run()
{
   // glfw: initialize and configure
// ------------------------------
   glfwInit();
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
   glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

   // glfw window creation
   // --------------------
   GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
   if (window == NULL)
   {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return -1;
   }
   glfwMakeContextCurrent(window);
   glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
   glfwSetCursorPosCallback(window, mouse_callback);
   glfwSetScrollCallback(window, scroll_callback);

   // tell GLFW to capture our mouse
   glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

   // glad: load all OpenGL function pointers
   // ---------------------------------------
   if (glewInit())
   {
      std::cout << "Failed to initialize GLEW" << std::endl;
      return -1;
   }
   glewExperimental = true;

   // tell stb_image.h to flip loaded texture's on the y-axis (before loading model).
   stbi_set_flip_vertically_on_load(true);

   // configure global opengl state
   // -----------------------------
   glEnable(GL_DEPTH_TEST);

   // build and compile shaders
   // -------------------------
   Shader ourShader((RESOURCES_FOLDER_PATH + "/vertex_shader.vs").c_str(), (RESOURCES_FOLDER_PATH + "/fragment_shader.fs").c_str());

   // load models
   // -----------
   Model ourModel(RESOURCES_FOLDER_PATH + "/objects/backpack/backpack.obj");

   // draw in wireframe
   //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   
   // render loop
   // -----------
   while (!glfwWindowShouldClose(window))
   {
      // per-frame time logic
      // --------------------
      float currentFrame = static_cast<float>(glfwGetTime());
      deltaTime = currentFrame - lastFrame;
      lastFrame = currentFrame;

      // input
      // -----
      processInput(window);

      // render
      // ------
      glClearColor(0.05f, 0.75f, 0.05f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      // don't forget to enable shader before setting uniforms
      ourShader.use();

      // view/projection transformations
      glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
      glm::mat4 view = camera.GetViewMatrix();
      ourShader.setMat4("projection", projection);
      ourShader.setMat4("view", view);

      // render the loaded model
      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
      model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
      ourShader.setMat4("model", model);
      ourModel.Draw(ourShader);

      // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
      // -------------------------------------------------------------------------------
      glfwSwapBuffers(window);
      glfwPollEvents();
   }

   // glfw: terminate, clearing all previously allocated GLFW resources.
   // ------------------------------------------------------------------
   glfwTerminate();
   return 0;
}

void 
Game::shutdown()
{
   //delete m_test_window;
}

void Game::handleEvents()
{

}

void Game::update()
{

}

void Game::render()
{
   
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
   if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, true);

   if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
      camera.ProcessKeyboard(FORWARD, deltaTime);
   if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
      camera.ProcessKeyboard(BACKWARD, deltaTime);
   if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
      camera.ProcessKeyboard(LEFT, deltaTime);
   if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
      camera.ProcessKeyboard(RIGHT, deltaTime);

   if(glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
   // make sure the viewport matches the new window dimensions; note that width and 
   // height will be significantly larger than specified on retina displays.
   glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
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

   camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
   camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
