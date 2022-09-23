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

   std::vector<sf::Sprite*>
   getAnimationFrames();

   sf::Sprite*
   getNextFrame();

private:
   std::vector<sf::Sprite*> m_anim_frames;
   int m_current_frame;
};