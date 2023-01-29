#pragma once
#include "Entity.hh"
#include "EntityManager.hh"
#include <string>

class EntityBehaviour
{
protected:
  Entity& entity;
  const std::string entityName;
private:
  const EntityManager& entityManager;
public:
  EntityBehaviour(EntityManager& entityManager, std::string entityName);
  ~EntityBehaviour();
};