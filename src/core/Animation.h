#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Animation
{
public:
   Animation();

   void
   insertAnimationFrame(int insert_at, sf::Sprite* sprite);

   void
   insertAnimationFrames(int insert_at, std::vector<sf::Sprite*> sprites);

   void
   setIdleSprite(sf::Sprite* sprite);

   sf::Sprite*
   getIdleSprite();

   std::vector<sf::Sprite*>
   getAnimationFrames();

   sf::Sprite*
   getNextFrame();

   void
   saveAnimation(const std::string& filename);

private:
   std::vector<sf::Sprite*> m_anim_frames;
   sf::Clock m_animation_timer;
   sf::Time m_last_animation_time;
   sf::Sprite* m_idle_sprite;
   int m_current_frame;
};