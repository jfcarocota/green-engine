#pragma once
#include "Components/Component.hh"
#include "Components/TransformComponent.hh"

class Movement: public Component
{
private:
  float moveSpeed;
  TransformComponent& transform;
public:
  Movement(float moveSpeed, TransformComponent& transform);
  ~Movement();
  void Initialize() override;
  void Update(float& deltaTime) override;
};