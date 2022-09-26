#include "Character.h"

Character::Character() :
   m_moving(false),
   m_facing(FORWARD)
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
   Animation* animation = m_movement_animations.at(FORWARD);
   target.draw(*animation->getAnimationFrames()[0]);
}

void
Character::update(const sf::Event& event)
{

}
