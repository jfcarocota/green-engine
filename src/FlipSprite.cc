#include "FlipSprite.hh"
#include "InputSystem.hh"

FlipSprite::FlipSprite(SpriteComponent& spriteComponent, TransformComponent& transform):
spriteComponent(spriteComponent), transform(transform)
{
  
}

FlipSprite::~FlipSprite()
{
}

void FlipSprite::Update(float& deltaTime)
{
  sf::Vector2f axis = InputSystem::Axis();
  spriteComponent.SetFlipTexture(axis.x < 0 ? true : axis.x > 0 ? false : spriteComponent.GetFliptexture());
}
