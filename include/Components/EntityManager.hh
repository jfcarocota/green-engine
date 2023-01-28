#pragma once
#include "Component.hh"
#include "Entity.hh"
#include<vector>

class EntityManager
{
private:
  std::vector<Entity*> entities;
public:
  EntityManager(/* args */);
  ~EntityManager();

  void ClearData();
  void Update(float& deltaTime);
  void Render();
  bool HasNoEntities();
  Entity& AddEntity(std::string entityName);
  std::vector<Entity*> GetEntities() const;
  unsigned int GetentityCount() const;
};