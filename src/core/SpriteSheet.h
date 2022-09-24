#pragma once

#include "Util.h"

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <SFML/Graphics.hpp>

struct SpriteInfo
{
   std::string m_sheet_path;
   int m_x_res;
   int m_y_res;

   std::vector<std::vector<int>> m_sprite_coords;
};

class SpriteSheet
{
   public:
      SpriteSheet();

      SpriteSheet(
         const sf::Texture& texture, 
         const unsigned int x_res,
         const unsigned int y_res);

      SpriteSheet(const SpriteInfo& sprite_info);

      void
      init(const rapidxml::xml_document<>& doc);
   
      sf::Sprite* operator [](int i) const { return m_sprites[i]; }

   private:
      void cutSpriteSheet();

      std::vector<sf::Sprite*> m_sprites;
      
      sf::Texture m_texture;
      unsigned int m_x_res;
      unsigned int m_y_res;
};
