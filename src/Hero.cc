#include "Hero.hh"
#include "Components/TransformComponent.hh"
#include "Components/SpriteComponent.hh"
#include "Movement.hh"
#include "FlipSprite.hh"
#include "Components/RigidBodyComponent.hh"
#include "Components/AnimatorComponent.hh"

Hero::Hero(float moveSpeed, b2World*& world)
{
  this->world = world;
  this->moveSpeed = moveSpeed;
}

Hero::~Hero()
{
}

void Hero::Initialize()
{
  TransformComponent& transform = owner->AddComponent<TransformComponent>(500.f, 300.f, 16.f, 16.f, 4.f);
  SpriteComponent& sprite = owner->AddComponent<SpriteComponent>("assets/sprites.png", transform, 0, 5);
  RigidBodyComponent& rigidbody = owner->AddComponent<RigidBodyComponent>(world, b2BodyType::b2_dynamicBody,
   1, 0, 0, 0.f, (void*) this, transform, sprite);
  AnimatorComponent& animator = owner->AddComponent<AnimatorComponent>();
  owner->AddComponent<Movement>(moveSpeed, rigidbody, animator);
  owner->AddComponent<FlipSprite>(sprite, transform);
}
