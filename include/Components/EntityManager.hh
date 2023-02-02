#pragma once
#include<SFML/Graphics.hpp>
#include "Component.hh"
#include "Entity.hh"
#include<vector>

class EntityManager
{
private:
  std::vector<Entity*> entities;
  std::vector<Entity*> acttiveEntities;
  std::vector<Entity*> inactiveEntities;
public:
  EntityManager(/* args */);
  ~EntityManager();

  void ClearData();
  void Update(float& deltaTime);
  void Render(sf::RenderWindow& window);
  bool HasNoEntities();
  Entity& AddEntity(std::string entityName);
  std::vector<Entity*> GetEntities() const;
  unsigned int GetentityCount() const;
};