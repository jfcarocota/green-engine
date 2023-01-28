#pragma once

class Entity;

class Component
{
public:
  Entity* entity{};

  virtual ~Component(){}
  virtual void Initialize(){}
  virtual void Update(float& deltaTime){}
  virtual void Render(){}
};
