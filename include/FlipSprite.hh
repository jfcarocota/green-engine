#pragma once
#include "Components/Component.hh"
#include "Components/SpriteComponent.hh"
#include "Components/TransformComponent.hh"

class FlipSprite: public Component
{
private:
  SpriteComponent& spriteComponent;
  TransformComponent& transform;
public:
  FlipSprite(SpriteComponent& spriteComponent, TransformComponent& transform);
  ~FlipSprite();
  void Update(float& deltaTime) override;
};