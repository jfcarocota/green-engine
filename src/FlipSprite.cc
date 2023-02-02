#include "FlipSprite.hh"
#include "InputSystem.hh"
#include "Components/EntityManager.hh"

FlipSprite::FlipSprite()
{
  
}

FlipSprite::~FlipSprite()
{
}

void FlipSprite::Initialize()
{
  transform = owner->GetComponent<TransformComponent>();
  spriteComponent = owner->GetComponent<SpriteComponent>();
}

void FlipSprite::Update(float& deltaTime)
{
  sf::Vector2f axis = InputSystem::Axis();
  spriteComponent->SetFlipTexture(axis.x < 0 ? true : axis.x > 0 ? false : spriteComponent->GetFliptexture());
}
