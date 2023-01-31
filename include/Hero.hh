#pragma once

#include "Components/EntityManager.hh"
#include "Components/Component.hh"
#include<box2d/box2d.h>

class Hero: public Component
{
private:
  float moveSpeed;
  b2World* world;
public:
  Hero(float moveSpeed, b2World*& world);
  ~Hero();
  void Initialize() override;
};