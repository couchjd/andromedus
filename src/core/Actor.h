#pragma once

#include <SFML/Window.hpp>

typedef enum
{
   NONE,
   FORWARD,
   BACKWARD,
   LEFT,
   RIGHT
} movement_direction;

class Actor
{
public:
   Actor();

   virtual void update(const sf::Event& event) = 0;

   unsigned int
   getActorId();

private:
   unsigned int m_actor_id;

   static unsigned int s_next_actor_id;
};
