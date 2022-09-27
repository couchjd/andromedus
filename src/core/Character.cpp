#include "Character.h"

Character::Character() :
   m_moving(false),
   m_facing(FORWARD),
   m_active_sprite(nullptr)
{

}

void
Character::addMovementAnimation(const
   movement_direction dir,
   Animation* animation)
{
   m_movement_animations[dir] = animation;
}

void
Character::draw(
   sf::RenderTarget& target,
   sf::RenderStates states) const
{
   if (m_active_sprite)
   {
      target.draw(*m_active_sprite);
   }
}

void
Character::update(const sf::Event& event)
{
   Animation* animation = m_movement_animations.at(m_facing);
   
   if (m_moving)
   {
      m_active_sprite = animation->getNextFrame();
   }
   else
   {
      m_active_sprite = animation->getIdleSprite();
   }
}

void 
Character::setFacing(const movement_direction facing)
{
   m_facing = facing;
}

bool Character::getIsMoving()
{
   return m_moving;
}

void Character::setIsMoving(bool is_moving)
{
   m_moving = is_moving;
}
