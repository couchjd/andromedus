#include "ActorUpdateManager.h"

ActorUpdateManager::ActorUpdateManager() :
   m_player_character(nullptr)
{
}

void
ActorUpdateManager::addActor(Actor* actor)
{
   m_actors_map[actor->getActorId()] = actor;
}

void
ActorUpdateManager::removeActor(Actor* actor)
{
   m_actors_map.erase(actor->getActorId());
}

Actor* 
ActorUpdateManager::getPlayerCharacter()
{
    return m_actors_map.at(1);
}

void
ActorUpdateManager::update(const sf::Event& event)
{
   for (auto actor : m_actors_map)
   {
      actor.second->update(event);
   }
}