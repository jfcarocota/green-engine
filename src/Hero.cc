#include "Hero.hh"
#include "Components/TransformComponent.hh"
#include "Components/SpriteComponent.hh"

Hero::Hero(EntityManager& entityManager): EntityBehaviour(entityManager, "hero")
{
  TransformComponent& transform = entity.AddComponent<TransformComponent>(500.f, 300.f, 16.f, 16.f, 4.f);
  entity.AddComponent<SpriteComponent>("assets/sprites.png", transform, 0, 5);
}

Hero::~Hero()
{
}
