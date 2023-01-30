#pragma once
#include "Component.hh"
#include "TransformComponent.hh"
#include<SFML/Graphics.hpp>

class SpriteComponent: public Component
{
private:
  const TransformComponent& transform;
  sf::Texture texture{};
  sf::Sprite sprite{};
  const char* textureUrl{};
  unsigned int col{}, row{};
public:
  SpriteComponent(const char* textureUrl, TransformComponent& transform, unsigned int col, unsigned int row);
  ~SpriteComponent();
  void Update(float& deltaTime) override;
  void Render(sf::RenderWindow& window) override;
};
