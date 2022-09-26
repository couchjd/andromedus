#include "ActorUpdateManager.h"

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

void
ActorUpdateManager::update(const sf::Event& event)
{
   for (auto actor : m_actors_map)
   {
      actor.second->update(event);
   }
}