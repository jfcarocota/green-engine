#pragma once
#include<SFML/Graphics.hpp>

class Entity;

class Component
{
public:
  Entity* owner{};

  virtual ~Component(){}
  virtual void Initialize(){}
  virtual void Update(float& deltaTime){}
  virtual void Render(sf::RenderWindow& window){}
};
