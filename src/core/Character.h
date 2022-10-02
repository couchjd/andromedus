#pragma once

#include "Actor.h"
#include "Animation.h"
#include "SpriteSheet.h"

#include <map>

class Character : public sf::Drawable, public Actor
{
public:
   Character();

   void
   init();

   void addMovementAnimation(
      const movement_direction,
      Animation* animation);

   virtual void draw(
      sf::RenderTarget& target,
      sf::RenderStates states) const override;

   virtual void update(const sf::Event& event) override;

   void setFacing(const movement_direction facing);

   bool getIsMoving();

   void setIsMoving(bool is_moving);

   void loadSpriteSheet();

   void initAnimations();

protected:
   movement_direction m_facing;
   bool m_moving;
   SpriteSheet m_sprite_sheet;
   sf::Sprite* m_active_sprite;
   
   std::map<movement_direction, Animation*> m_movement_animations;
};