#pragma once
#include "Components/Component.hh"
#include "Components/RigidBodyComponent.hh"
#include "Components/AnimatorComponent.hh"

class Movement: public Component
{
private:
  float moveSpeed;
  RigidBodyComponent& rigidbody;
  AnimatorComponent& animator;
public:
  Movement(float moveSpeed, RigidBodyComponent& rigidbody, AnimatorComponent& animator);
  ~Movement();
  void Initialize() override;
  void Update(float& deltaTime) override;
};