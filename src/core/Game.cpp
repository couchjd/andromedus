#include "Game.h"

#include <Camera.h>
#include <Model.h>
#include <Shader.h>
#include <Util.h>

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
   m_main_window = new Window();
   m_main_window->init(SCR_WIDTH, SCR_HEIGHT, "Andromedus", nullptr, nullptr);
   m_camera = new Camera();

   glfwSetWindowUserPointer(m_main_window->getGLWindow(), reinterpret_cast<void*>(this));

}

int
Game::run()
{
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
   while (!m_main_window->shouldClose())
   {
      // per-frame time logic
      // --------------------
      float currentFrame = static_cast<float>(glfwGetTime());
      deltaTime = currentFrame - lastFrame;
      lastFrame = currentFrame;

      // input
      // -----
      processInput(m_main_window->getGLWindow());

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
      glfwSwapBuffers(m_main_window->getGLWindow());
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