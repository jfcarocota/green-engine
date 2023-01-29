#pragma once

#include "Components/EntityManager.hh"
#include "Components/Entity.hh"

class Hero: public Entity
{
private:
  const EntityManager& entityManager{};
public:
  Hero(EntityManager& entityManager);
  ~Hero();
};