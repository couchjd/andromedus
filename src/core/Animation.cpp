#include "Animation.h"

//-----------------------------------------------------------------------------
Animation::Animation() :
   m_current_frame(0)
{

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
   int current_frame = m_current_frame;

   m_current_frame++;

   if (m_current_frame >= m_anim_frames.size())
   {
      m_current_frame = 0;
   }

   return m_anim_frames[current_frame];
}
