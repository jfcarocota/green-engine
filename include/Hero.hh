#pragma once

#include "Components/EntityManager.hh"
#include "Components/EntityBehaviour.hh"

class Hero: public EntityBehaviour
{
private:
public:
  Hero(EntityManager& entityManager);
  ~Hero();
};