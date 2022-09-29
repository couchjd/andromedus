#include "Game.h"

int main()
{
   Game game;
   game.init();
   game.run();

   sf::Shader shader;
   std::string v_shader_path = RESOURCES_FOLDER_PATH + "/bloom.vs";
   std::string f_shader_path = RESOURCES_FOLDER_PATH + "/bloom.fs";

   if (!shader.loadFromFile(v_shader_path, f_shader_path))
   {
      std::cout << "FAILED TO LOAD SHADER!\n";
   }

   return 0;
}
