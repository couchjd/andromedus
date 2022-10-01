#include "Player.h"

void Player::update(const sf::Event& event)
{
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
