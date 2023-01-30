#include "Hero.hh"
#include "Components/TransformComponent.hh"
#include "Components/SpriteComponent.hh"
#include "Movement.hh"

Hero::Hero()
{

}

Hero::~Hero()
{
}

void Hero::Initialize()
{
  TransformComponent& transform = owner->AddComponent<TransformComponent>(500.f, 300.f, 16.f, 16.f, 4.f);
  owner->AddComponent<SpriteComponent>("assets/sprites.png", transform, 0, 5);
  owner->AddComponent<Movement>(200.f, transform);
}
