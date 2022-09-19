#pragma once
#include <SFML/Graphics.hpp>

class SpriteSheet
{
   public:
      SpriteSheet(
         const sf::Texture& texture, 
         const unsigned int x_res,
         const unsigned int y_res);
   
   private:
      void cutSpriteSheet();

      std::vector<sf::Sprite*> m_sprites;
      
      sf::Texture m_texture;
      unsigned int m_x_res;
      unsigned int m_y_res;
};
