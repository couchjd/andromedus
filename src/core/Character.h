#pragma once

#include "Actor.h"
#include "Animation.h"

#include <map>

class Character : public sf::Drawable, public Actor
{
public:
   Character();

   void addMovementAnimation(
      const movement_direction,
      Animation* animation);

   virtual void draw(
      sf::RenderTarget& target,
      sf::RenderStates states) const override;

   void update(const sf::Event& event) override;

   void setFacing(const movement_direction facing);

   bool getIsMoving();

   void setIsMoving(bool is_moving);

private:
   movement_direction m_facing;
   bool m_moving;
   sf::Sprite* m_active_sprite;
   
   std::map<movement_direction, Animation*> m_movement_animations;
};