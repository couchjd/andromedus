#include "Actor.h"

Actor::Actor() :
   m_actor_id(s_next_actor_id++)
{
}

unsigned int
Actor::getActorId()
{
   return m_actor_id;
}

unsigned int Actor::s_next_actor_id = 1;