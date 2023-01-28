#include "Components/TransformComponent.hh"

TransformComponent::TransformComponent(float posX, float posY, float width, float height, float scale)
{
  position = sf::Vector2(posX, posY);
  this->width = width;
  this->height = height;
  this->scale = scale;
}

TransformComponent::~TransformComponent()
{

}

void TransformComponent::Initialize()
{

}
void TransformComponent::Update(float& deltaTime)
{

}