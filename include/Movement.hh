#pragma once
#include "Components/Component.hh"
#include "Components/RigidBodyComponent.hh"

class Movement: public Component
{
private:
  float moveSpeed;
  RigidBodyComponent& rigidbody;
public:
  Movement(float moveSpeed, RigidBodyComponent& rigidbody);
  ~Movement();
  void Initialize() override;
  void Update(float& deltaTime) override;
};