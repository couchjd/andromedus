#pragma once

#include "Animation.h"

#include <map>

typedef enum
{
   FORWARD,
   BACKWARD,
   LEFT,
   RIGHT
} movement_direction;

class Character : public sf::Drawable
{
public:
   Character();

   void addMovementAnimation(
      const movement_direction,
      Animation* animation);

   virtual void draw(
      sf::RenderTarget& target,
      sf::RenderStates states) const override;

private:
   movement_direction m_facing;
   bool m_moving;
   
   std::map<movement_direction, Animation*> m_movement_animations;
};