#pragma once
#include "Components/Component.hh"
#include "Components/TransformComponent.hh"
#include "Components/EntityManager.hh"
#include <functional>

class Button: public Component
{
private:
  sf::RectangleShape rectangleShape;
  float borderSize;
  sf::Color fillColor;
  sf::Color borderColor;
  TransformComponent& transform;
  std::function<void()> onClickAction;
  bool clicked = false;
public:
  Button(TransformComponent& transform, float borderSize, sf::Color fillColor, sf::Color borderColor, std::function<void()> onClickAction);
  ~Button();
  void OnClick();
  void Initialize() override;
  void Update(float& deltaTime) override;
  void Render(sf::RenderWindow& window) override;
};
