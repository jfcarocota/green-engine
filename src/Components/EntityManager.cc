#include "Components/EntityManager.hh"

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{

}

void EntityManager::ClearData()
{
  for(auto& entity : entities)
  {
    entity->Destroy();
  }
}

bool EntityManager::HasNoEntities()
{
  return entities.size() == 0;
}

void EntityManager::Update(float& deltaTime)
{
  for(auto& entity : entities)
  {
    if(entity->IsActive())
    {
      entity->Update(deltaTime);
    }
    else
    {
      entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
      delete entity;
    }
  }
}

void EntityManager::Render(sf::RenderWindow& window)
{
  for(auto& entity : entities)
  {
    if(entity->IsActive())
    {
      entity->Render(window);
    }
  }
}

Entity& EntityManager::AddEntity(std::string entityName)
{
  Entity* entity{new Entity(*this, entityName)};
  entities.emplace_back(entity);
  return *entity;
}

std::vector<Entity*> EntityManager::GetEntities() const
{
  return entities;
}