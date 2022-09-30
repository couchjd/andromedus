#pragma once

#include "Actor.h"

#include <unordered_map>

class ActorUpdateManager
{
public:
   ActorUpdateManager();

   void
   addActor(Actor* actor);

   void
   removeActor(Actor* actor);

   void 
   setPlayerCharacter(Actor* player_character);

   Actor*
   getPlayerCharacter();

   void
   update(const sf::Event& event);

private:
   std::unordered_map<unsigned int, Actor*> m_actors_map;
   Actor* m_player_character;
};