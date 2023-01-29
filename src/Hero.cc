#include "Hero.hh"
#include "Components/TransformComponent.hh"
#include "Components/SpriteComponent.hh"

Hero::Hero(EntityManager& entityManager): entityManager(entityManager), Entity(entityManager.AddEntity("hero"))
{
  TransformComponent& transform = this->AddComponent<TransformComponent>(500.f, 300.f, 16.f, 16.f, 4.f);
  this->AddComponent<SpriteComponent>("assets/sprites.png", transform, 0, 5);
}

Hero::~Hero()
{
}
