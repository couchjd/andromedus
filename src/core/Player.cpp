#include "Player.h"

Player::Player()
{
   std::string v_shader_path = RESOURCES_FOLDER_PATH + "/bloom.vs";
   std::string f_shader_path = RESOURCES_FOLDER_PATH + "/bloom.fs";

   if (!m_shader.loadFromFile(v_shader_path, f_shader_path))
   {
      std::cout << "FAILED TO LOAD SHADER!\n";
   }

}

void Player::update(const sf::Event& event)
{
   sf::Transform* transform = new sf::Transform(1.0, 0.0, 0.0,
                                                0.0, 0.0, 0.0,
                                                0.0, 0.0, 0.0);
   sf::Glsl::Vec4 color(1.0, 0.0, 0.0, 1.0);
   sf::Glsl::Mat4* matrix = new sf::Glsl::Mat4(*transform);
   m_shader.setUniform("ourColor", color);
   //m_shader.setUniform("matrix", *matrix);
   //m_shader.setUniform("t0", m_shader.CurrentTexture);

   if (event.type == sf::Event::KeyPressed)
   {
      movement_direction face_dir = NONE;

      switch (event.key.code)
      {
         case sf::Keyboard::W:
         {
            face_dir = BACKWARD;
            break;
         }
         case sf::Keyboard::A:
         {
            face_dir = LEFT;
            break;
         }
         case sf::Keyboard::S:
         {
            face_dir = FORWARD;
            break;
         }
         case sf::Keyboard::D:
         {
            face_dir = RIGHT;
            break;
         }
      }
      if (face_dir != NONE)
      {
         setFacing(face_dir);

         if (!m_moving)
         {
            m_moving = true;
         }
      }
   }
   if (event.type == sf::Event::KeyReleased)
   {
      if (event.key.code == sf::Keyboard::W ||
          event.key.code == sf::Keyboard::A ||
          event.key.code == sf::Keyboard::S ||
          event.key.code == sf::Keyboard::D)
      {
         if (m_moving)
         {
            m_moving = false;
         }
      }
   }
   
   Character::update(event);
}

sf::Shader& Player::getShader()
{
   return m_shader;
}
