#include "Candle.hh"
#include "Components/TransformComponent.hh"
#include "Components/SpriteComponent.hh"
#include "Components/RigidBodyComponent.hh"
#include "Components/AnimatorComponent.hh"
#include "AnimationClip.hh"

Candle::Candle(b2World*& world)
{
  this->world = world;
}

Candle::~Candle()
{
}

void Candle::Initialize()
{
  TransformComponent& transform = owner->AddComponent<TransformComponent>(500.f, 500.f, 16.f, 16.f, 4.f);
  SpriteComponent& sprite = owner->AddComponent<SpriteComponent>("assets/sprites.png", transform, 0, 5);
  RigidBodyComponent& rigidbody = owner->AddComponent<RigidBodyComponent>(world, b2BodyType::b2_staticBody,
   1, 0, 0, 0.f, (void*) this, transform, sprite);
  AnimatorComponent& animator = owner->AddComponent<AnimatorComponent>(sprite, transform);

  animator.AddAnimation("idle", AnimationClip("assets/animations/candle/idle.json"));

}