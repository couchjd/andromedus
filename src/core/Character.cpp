#include "Character.h"
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

Character::Character() :
   m_moving(false),
   m_facing(FORWARD),
   m_active_sprite(nullptr)
{

}

void Character::init()
{
   loadSpriteSheet();
   initAnimations();
   m_active_sprite = m_movement_animations[FORWARD]->getIdleSprite();
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

void Character::loadSpriteSheet()
{
   std::string path = RESOURCES_FOLDER_PATH + "/sprite_test.xml";

   rapidxml::file<> file(path.data());
   rapidxml::xml_document<> doc;
   doc.parse<0>(file.data());

   m_sprite_sheet.init(doc);
}

void Character::initAnimations()
{
   Animation* forward = new Animation();
   Animation* left = new Animation();
   Animation* back = new Animation();
   Animation* right = new Animation();

   forward->setIdleSprite(m_sprite_sheet[1]);
   forward->insertAnimationFrame(0, m_sprite_sheet[0]);
   forward->insertAnimationFrame(1, m_sprite_sheet[2]);
   left->setIdleSprite(m_sprite_sheet[4]);
   left->insertAnimationFrame(0, m_sprite_sheet[3]);
   left->insertAnimationFrame(1, m_sprite_sheet[5]);
   back->setIdleSprite(m_sprite_sheet[10]);
   back->insertAnimationFrame(0, m_sprite_sheet[9]);
   back->insertAnimationFrame(1, m_sprite_sheet[11]);
   right->setIdleSprite(m_sprite_sheet[7]);
   right->insertAnimationFrame(0, m_sprite_sheet[6]);
   right->insertAnimationFrame(1, m_sprite_sheet[8]);

   addMovementAnimation(FORWARD, forward);
   addMovementAnimation(LEFT, left);
   addMovementAnimation(BACKWARD, back);
   addMovementAnimation(RIGHT, right);
}
