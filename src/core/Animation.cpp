#include "Animation.h"

#define UPDATE_INTERVAL_MS 100

//-----------------------------------------------------------------------------
Animation::Animation() :
   m_current_frame(0),
   m_idle_sprite(nullptr)
{
   m_last_animation_time = m_animation_timer.restart();
}

//-----------------------------------------------------------------------------
void 
Animation::insertAnimationFrame(int insert_at, sf::Sprite* sprite)
{
   std::vector<sf::Sprite*>::iterator it = m_anim_frames.begin();

   m_anim_frames.insert(it + insert_at, sprite);
}

//-----------------------------------------------------------------------------
void 
Animation::insertAnimationFrames(int insert_at, std::vector<sf::Sprite*> sprites)
{
   std::vector<sf::Sprite*>::iterator it = m_anim_frames.begin();

   m_anim_frames.insert(it + insert_at, sprites.begin(), sprites.end());
}

//-----------------------------------------------------------------------------
void 
Animation::setIdleSprite(sf::Sprite* sprite)
{
   m_idle_sprite = sprite;
}

//-----------------------------------------------------------------------------
sf::Sprite* 
Animation::getIdleSprite()
{
   return m_idle_sprite;
}

//-----------------------------------------------------------------------------
std::vector<sf::Sprite*> 
Animation::getAnimationFrames()
{
   return m_anim_frames;
}

//-----------------------------------------------------------------------------
/* Update the current frame and return the sprite to be displayed.           */    
//-----------------------------------------------------------------------------
sf::Sprite* 
Animation::getNextFrame()
{
   sf::Time elapsed = m_animation_timer.getElapsedTime();

   double delta = elapsed.asMilliseconds() - m_last_animation_time.asMilliseconds();

   if (delta >= UPDATE_INTERVAL_MS)
   {
      m_current_frame++;

      if (m_current_frame >= m_anim_frames.size())
      {
         m_current_frame = 0;
      }
      
      m_animation_timer.restart();
   }

   return m_anim_frames[m_current_frame];
}
