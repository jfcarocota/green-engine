#pragma once

#include "Component.hh"
#include <SFML/Graphics.hpp>

class TransformComponent: public Component
{
private:
  sf::Vector2f position{};
  float width{};
  float height{};
  float scale{};
public:
  TransformComponent(float posX, float posY, float width, float height, float scale);
  ~TransformComponent();
  void Initialize();
  void Update(float& deltaTime);
};