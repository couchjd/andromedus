#include "ActorUpdateManager.h"
#include "Player.h"

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
      // Player Character should have m_actor_id == 1
      if (actor.second->getActorId() == 1)
      {
         Player* player = dynamic_cast<Player*>(actor.second);
         if (player)
         {
            player->update(event);
         }
      }
      else
      {
         actor.second->update(event);
      }
   }
}