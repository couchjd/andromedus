#include "SpriteSheet.h"

//-----------------------------------------------------------------------------
SpriteSheet::SpriteSheet(
   const sf::Texture& texture, 
   const unsigned int x_res, 
   const unsigned int y_res) : 
   m_texture(texture),
   m_x_res(x_res),
   m_y_res(y_res)
{
   cutSpriteSheet();
}

//-----------------------------------------------------------------------------
SpriteSheet::SpriteSheet(const SpriteInfo& sprite_info) :
   m_x_res(sprite_info.m_x_res),
   m_y_res(sprite_info.m_y_res)
{
   std::string texture_path = SPRITES_FOLDER_PATH + "/" + sprite_info.m_sheet_path;
   
   bool status = m_texture.loadFromFile(texture_path);
   
   for (const auto& coord_set : sprite_info.m_sprite_coords)
   {
      sf::IntRect sprite_rect(coord_set[0], coord_set[1], m_x_res, m_y_res);
      m_sprites.push_back(new sf::Sprite(m_texture, sprite_rect));
   }
}

//-----------------------------------------------------------------------------
void 
SpriteSheet::cutSpriteSheet()
{
   sf::Vector2u texture_size = m_texture.getSize();
   unsigned int y_stride = texture_size.y / m_y_res;
   unsigned int x_stride = texture_size.x / m_x_res;

   for (int y = 0; y < texture_size.y; y += m_y_res)
   {
      for (int x = 0; x < texture_size.x; x += m_x_res)
      {
         sf::IntRect sprite_rect(x, y, m_x_res, m_y_res);
         m_sprites.push_back(new sf::Sprite(m_texture, sprite_rect));
      }
   }

   sf::Texture texture;
}

//-----------------------------------------------------------------------------