#pragma once
#include "Components/Component.hh"
#include "Components/RigidBodyComponent.hh"
#include "Components/AnimatorComponent.hh"
#include "Components/TransformComponent.hh"
#include "Components/SpriteComponent.hh"

class Movement: public Component
{
private:
  float moveSpeed;
  RigidBodyComponent& rigidbody;
  AnimatorComponent& animator;
  TransformComponent& transform;
  SpriteComponent& sprite;
public:
  Movement(float moveSpeed, RigidBodyComponent& rigidbody,
  AnimatorComponent& animator, TransformComponent& transform,
  SpriteComponent& sprite);
  ~Movement();
  void Initialize() override;
  void Update(float& deltaTime) override;
};