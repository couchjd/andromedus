#pragma once

#include "Actor.h"

#include <unordered_map>

class ActorUpdateManager
{
public:
   void
   addActor(Actor* actor);

   void
   removeActor(Actor* actor);

   void
   update(const sf::Event& event);

private:
   std::unordered_map<unsigned int, Actor*> m_actors_map;
};