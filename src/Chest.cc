#include "Chest.hh"
#include "Components/TransformComponent.hh"
#include "Components/SpriteComponent.hh"
#include "Components/RigidBodyComponent.hh"

Chest::Chest(b2World*& world): world(world)
{

}

Chest::~Chest()
{
}

void Chest::Initialize()
{
  TransformComponent& transform = owner->AddComponent<TransformComponent>(300.f, 500.f, 16.f, 16.f, 4.f);
  SpriteComponent& sprite = owner->AddComponent<SpriteComponent>("assets/sprites.png", transform, 6, 1);
  RigidBodyComponent& rigidbody = owner->AddComponent<RigidBodyComponent>(world, b2BodyType::b2_staticBody,
   1, 0, 0, 0.f, true, (void*) owner, transform, sprite);
}